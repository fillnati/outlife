class TZToxicZoneCore
{
	ref StaticToxicAreaSettings 						m_ActiveStaticToxicAreaSettings;
	ref GeneralToxicZoneSettings 						m_ActiveGeneralToxicZoneSettings;
	ref MovingToxicAreaSettings 						m_ActiveMovingToxicAreaSettings;
	ref LootTZSettings 											m_ActiveLootSettings;

	ref TZClotheProtectionSettings 					m_TZClotheProtectionSettings;
	ref TZClotheProtectionSettings 					m_TZClotheProtectionSettingsClient;

  ref TZToxicZoneClient 									m_TZToxicZoneClient;
  ref TZToxicZoneServer 									m_TZToxicZoneServer;
	ref TZCrateSystem    										m_TZCrateSystem;

	ref array<ref TZMovingToxicZoneClient> 	m_TZMovingToxicZones;
	ref array<ref MovingToxicZoneLocation> 	m_MovingToxicZoneLocations;
	ref array<int>													m_StartTimes;

	bool 																		m_isTransfertFinished = false;

	void TZToxicZoneCore()
  {
		GetTZLogger().LogInfo("TZToxicZoneCore - Started ! => Loading config...");
		#ifdef TZDEBUG
		GetTZLogger().LogInfo("DEBUG MODE ENABLED");
		#endif
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			//LOADING CONFIG FILES...
			m_TZClotheProtectionSettings = TZClotheProtectionSettings.Load();
			m_ActiveGeneralToxicZoneSettings = GeneralToxicZoneSettings.Load();
			m_ActiveMovingToxicAreaSettings = MovingToxicAreaSettings.Load();
			m_ActiveStaticToxicAreaSettings = StaticToxicAreaSettings.Load();
			m_ActiveLootSettings = LootTZSettings.Load();

			//Creating server side part of the cratesystem
			if(m_ActiveLootSettings.IsActive)
			{
				m_TZCrateSystem = new TZCrateSystem;
			}

			//Creating server side part of the statictoxiczone
			if(m_ActiveStaticToxicAreaSettings.IsToxicZoneActive)
			{
				m_TZToxicZoneServer = new TZToxicZoneServer;
			}

			//Creating server side part of the movingtoxiczone
			if(m_ActiveMovingToxicAreaSettings.IsMovingZoneActive)
			{
				m_MovingToxicZoneLocations = new array<ref MovingToxicZoneLocation>;
				m_StartTimes = new array<int>;
				GetTZLogger().LogInfo("MVTZ Count:"+m_ActiveMovingToxicAreaSettings.MovingToxicAreaLocation.Count().ToString());
				for (int k=0;k<m_ActiveMovingToxicAreaSettings.MovingToxicAreaLocation.Count();k++)
				{
					if(m_ActiveMovingToxicAreaSettings.MovingToxicAreaLocation.Get(k).Chance > Math.RandomFloat01())
					{
						GetTZLogger().LogInfo("MovingToxicZone Spawned at X:"+m_ActiveMovingToxicAreaSettings.MovingToxicAreaLocation.Get(k).StartX.ToString() + " Y:" + m_ActiveMovingToxicAreaSettings.MovingToxicAreaLocation.Get(k).StartY);
						m_MovingToxicZoneLocations.Insert(m_ActiveMovingToxicAreaSettings.MovingToxicAreaLocation.Get(k));
						m_StartTimes.Insert(TZGetTimeStamp());
					}
				}
			}
		}
		else
		{
			m_TZClotheProtectionSettingsClient = new TZClotheProtectionSettings;
			m_TZToxicZoneClient = new TZToxicZoneClient;
			m_TZMovingToxicZones = new array<ref TZMovingToxicZoneClient>;
		}
		InitRPC();
  }

	void ~TZToxicZoneCore(){
  }

	void InitRPC()
		{
			if (GetGame().IsServer())	{
				//Server calls
				GetRPCManager().AddRPC("TZToxicZone", "GetToxicStatut", m_TZToxicZoneServer, SingeplayerExecutionType.Client);
				GetRPCManager().AddRPC("TZToxicZone", "GetSickQtyToGive", m_TZToxicZoneServer, SingeplayerExecutionType.Client);
			}
			else	{
				//Client calls
				GetRPCManager().AddRPC("TZToxicZone", "GetToxicConfigResponse", m_TZToxicZoneClient, SingeplayerExecutionType.Server);
				GetRPCManager().AddRPC("TZToxicZone", "GetToxicZoneClotheConfigResponse", this, SingeplayerExecutionType.Server);
				GetRPCManager().AddRPC("TZToxicZone", "GetMovingToxicZoneConfigResponse", this, SingeplayerExecutionType.Server);
			}
		}

		//----------------------------------RPC PART---------------------------------------------------//
		void TransfertClotheProtectionConfigToClient(PlayerIdentity idy = NULL)
		{
			bool rep = false;
			for(int i = 0;i<m_TZClotheProtectionSettings.TZListSlotProtection.Count();i++)
			{
				TZClotheConfigTemp m_TZClotheConfigTemp;
			  m_TZClotheConfigTemp = new TZClotheConfigTemp(i,m_TZClotheProtectionSettings);
				if(i == -1 + m_TZClotheProtectionSettings.TZListSlotProtection.Count())rep = true;
				GetRPCManager().SendRPC("TZToxicZone", "GetToxicZoneClotheConfigResponse", new Param3<ref TZClotheConfigTemp,bool, int>(m_TZClotheConfigTemp,rep,m_TZClotheProtectionSettings.RequiredProtection), true, idy);
	      m_TZClotheConfigTemp=NULL;
			}
		}

		void GetToxicZoneClotheConfigResponse(CallType type,  ParamsReadContext ctx,  PlayerIdentity sender,  Object target)
		{
				if (!GetGame().IsClient())
						return;
				Param3<ref TZClotheConfigTemp,bool,int> data;
				if (!ctx.Read(data))
						return;
				//Creation of an other protection config on client side
				if(m_isTransfertFinished)
				{
					m_TZClotheProtectionSettingsClient.TZListSlotProtection.Clear();
					m_isTransfertFinished = false;
				}
				TZClotheConfigTemp m_TZClotheConfigTemp = data.param1;
        m_TZClotheProtectionSettingsClient.RequiredProtection = data.param3;
				m_TZClotheProtectionSettingsClient.AddTZListSlotProtection(m_TZClotheConfigTemp.SlotName);
				m_TZClotheProtectionSettingsClient.AddTZProtectiveClothes(m_TZClotheConfigTemp.ClothesNames,m_TZClotheConfigTemp.Protection);
				if(data.param2)
				{
					m_isTransfertFinished = true;
					JsonFileLoader<TZClotheProtectionSettings>.JsonSaveFile(TZ_CP_CONFIG, m_TZClotheProtectionSettingsClient);
				}
		}

		void SendMovingToxicZoneConfig(PlayerIdentity sender = NULL)
		{
			GetTZLogger().LogInfo("m_MovingToxicZoneLocations count:"+m_MovingToxicZoneLocations.Count().ToString());
			for(int i = 0; i < m_MovingToxicZoneLocations.Count();i++)
			{
				int delta_t = TZGetTimeStamp() - m_StartTimes.Get(i);
				GetRPCManager().SendRPC("TZToxicZone", "GetMovingToxicZoneConfigResponse", new Param2<ref MovingToxicZoneLocation, int>(m_MovingToxicZoneLocations.Get(i),delta_t), true, sender);
			}
		}

		void GetMovingToxicZoneConfigResponse(CallType type,  ParamsReadContext ctx,  PlayerIdentity sender,  Object target)
    {
        if (!GetGame().IsClient())
            return;

        Param2<ref MovingToxicZoneLocation, int> data;
        if (!ctx.Read(data))
            return;
				Print("GetMovingToxicZoneConfigResponse");
        m_TZMovingToxicZones.Insert(new  TZMovingToxicZoneClient(data.param1, data.param2));
    }
		//------------------------------------------------------------------------------------------------//
};
