class TZToxicZoneClient
{
  int             NbSickGiven=0;
  string          TZName="";
  bool						TZStatut = false;
  int             RequiredProtection = 6;
  int             ClothesProtection = 0;
  bool            IsOnlyGasMask = false;
  bool            HasStarted = false;

  private ref array<string>m_Suits = {"GP5GasMask","NBCHoodBase","NBCJacketBase","NBCGloves_ColorBase","NBCPantsBase","NBCBootsBase"};
  private ref array<string>m_SLOTS = {"Mask","Headgear","Body","Gloves","Legs","Feet"};

  ref StaticToxicZoneLocationsClient m_ToxicLocations;

	void TZToxicZoneClient()
  {

  }

  void ~TZToxicZoneClient(){
  }


  void StartRadCheck()
  {
      HasStarted = true;
      //GetGame().GetMission().MissionScript.Call( this, "ToxicZoneCheck", null );
      //GetGame().GetMission().MissionScript.Call( this, "IsInsideToxicZone", null );
      GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(IsInsideToxicZone, 60000, true);
      GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ToxicZoneCheck, 2000, true);
  }

  private void IsInsideToxicZone()
  {
      if (TZStatut == true) //Already in zone
      {
        ProtectionCheckClient();
      }
  }

  private void ToxicZoneCheck()
	{
            PlayerBase m_player = PlayerBase.Cast(GetGame().GetPlayer());
            if(m_player)
            {
              if( m_ToxicLocations )
              {
          			for(int i = 0 ; i<m_ToxicLocations.X1.Count() ; i++)
          			{
                  if(TZStatut  && TZName != m_ToxicLocations.Statut.Get(i))continue;
          				if( m_ToxicLocations.IsSquareZone.Get(i) == 1)
          				{
          					ToxicZoneSquare(m_player,m_player.GetPosition(),m_ToxicLocations.X1.Get(i),m_ToxicLocations.Y1.Get(i),m_ToxicLocations.X2.Get(i),m_ToxicLocations.Y2.Get(i),m_ToxicLocations.Statut.Get(i),m_ToxicLocations.IsMsgActive.Get(i),m_ToxicLocations.MsgEnterZone.Get(i),m_ToxicLocations.MsgExitZone.Get(i),m_ToxicLocations.IsOnlyGasMask.Get(i));
          				}
          				else
          				{
          					ToxicZoneRound(m_player,m_player.GetPosition(),m_ToxicLocations.X.Get(i),m_ToxicLocations.Y.Get(i),m_ToxicLocations.Radius.Get(i),m_ToxicLocations.Statut.Get(i),m_ToxicLocations.IsMsgActive.Get(i),m_ToxicLocations.MsgEnterZone.Get(i),m_ToxicLocations.MsgExitZone.Get(i),m_ToxicLocations.IsOnlyGasMask.Get(i));
          				}
          			}
              }
            }
            else
            {
              TZStatut = false;
              TZName = "";
              NbSickGiven = 0;
              IsOnlyGasMask = false;
              ClothesProtection = 0;
              m_ToxicLocations = NULL;
            }
	}

  void ToxicZoneRound(PlayerBase m_player , vector pos,float m_X, float m_Y, float Zone_Radius,string Status,bool ismsgactive, string msgenterzone, string msgexitzone, bool isonlygasmask)
  {
    pos[1]=0;
    vector center = Vector(m_X,0,m_Y);
    float dist = vector.Distance(center, pos);
    if ( dist <= Zone_Radius )
		{
      if (TZName!=Status && !TZStatut)
			{
        if(m_player.GetCommand_Vehicle())
        {
          CarScript car = CarScript.Cast(m_player.GetCommand_Vehicle().GetTransport());
          if(car)
          {
            float car_dist = vector.Distance(center, car.GetPosition());
            if(car_dist > Zone_Radius)return;
          }
        }
        #ifdef TZDEBUG
        GetTZLogger().LogInfo("ToxicZoneRound:IsInside");
        #endif
        TZName=Status;
        TZStatut=true;
        IsOnlyGasMask = isonlygasmask;
        ProtectionCheckClient();
        SendToxicZoneStatut(TZName, TZStatut);
        if(!ismsgactive)return;
        NotificationSystem.AddNotificationExtended( 4, Status, msgenterzone, "ToxicZone_Data/data/Logo/Toxic.paa" );
      }
    }
    else
			{
        if (TZName==Status && TZStatut)
				{
          #ifdef TZDEBUG
          GetTZLogger().LogInfo("ToxicZoneRound:Is No longer Inside");
          #endif
          TZName="";
          TZStatut=false;
          IsOnlyGasMask = false;
          SendToxicZoneStatut(TZName, TZStatut);
          if(!ismsgactive)return;
          NotificationSystem.AddNotificationExtended( 4, Status, msgexitzone, "ToxicZone_Data/data/Logo/Toxic.paa" );
				}
			}
  }

  void 	ToxicZoneSquare(PlayerBase m_player ,vector pos, float m_X1, float m_Y1, float m_X2, float m_Y2,string Status,bool ismsgactive, string msgenterzone, string msgexitzone,bool isonlygasmask)
	{
    if ( pos[0]>m_X1 && pos[0]<m_X2 && pos[2]>m_Y1 && pos[2]< m_Y2 )
		{
      if (TZName!=Status && !TZStatut) //Already in zone
			{
        if(m_player.GetCommand_Vehicle())
        {
          CarScript car = CarScript.Cast(m_player.GetCommand_Vehicle().GetTransport());
          if(car)
          {
            vector car_dist = car.GetPosition();
            if(car_dist[0]>m_X1 && car_dist[0]<m_X2 && car_dist[2]>m_Y1 && car_dist[2]< m_Y2)
            {
              #ifdef TZDEBUG
              GetTZLogger().LogInfo("we're good");
              #endif
            }
            else return;
          }
        }
        TZName=Status;
        TZStatut=true;
        IsOnlyGasMask = isonlygasmask;
        ProtectionCheckClient();
        SendToxicZoneStatut(Status, true);
        if(!ismsgactive)return;
        NotificationSystem.AddNotificationExtended( 4, Status, msgenterzone, "ToxicZone_Data/data/Logo/Toxic.paa" );
      }
    }
    else
			{
        if (TZName==Status && TZStatut)
				{
          TZName="";
          TZStatut=false;
          IsOnlyGasMask = false;
          SendToxicZoneStatut(Status, false);
          if(!ismsgactive)return;
          NotificationSystem.AddNotificationExtended( 4, Status, msgexitzone, "ToxicZone_Data/data/Logo/Toxic.paa" );
				}
			}
	}

    void ProtectionCheckClient()
    {
      PlayerBase m_player = PlayerBase.Cast(GetGame().GetPlayer());
      if(!m_player)return;
      if(m_player.IsToxicSick)return;
      ClothesCheckClient(m_player);

      #ifdef TZDEBUG
      GetTZLogger().LogInfo("ClothesProtection:" + ClothesProtection.ToString());
      #endif
      if(GetTZClothesConfigClient().RequiredProtection > ClothesProtection )
      {
        float toxictogive = 0;
        if(IsOnlyGasMask)
        {
          RequiredProtection = 1;
        }else RequiredProtection = GetTZClothesConfigClient().RequiredProtection;
        toxictogive += NbSickGiven*(1.0-ClothesProtection/RequiredProtection*1.0);

        #ifdef TZDEBUG
        GetTZLogger().LogInfo("toxictogive:" + toxictogive.ToString());
        #endif

        if(toxictogive == 0)return;
        SendSicknessAmount(toxictogive);
      }
    }

    void ClothesCheckClient(PlayerBase player)
    {
        ClothesProtection=0;
        for (int i = 0; i <GetTZClothesConfigClient().TZListSlotProtection.Count() ;i++)
        {
          EntityAI SuitsPart;
          string slotname = GetTZClothesConfigClient().TZListSlotProtection.Get(i).SlotName;
          SuitsPart = player.FindAttachmentBySlotName(slotname);
          ClothesProtection += GetProtectionLevel(SuitsPart, i, slotname);
        }
    }

    float GetProtectionLevel(EntityAI attch, int i, string slotname)
    {
      int protection = 0;
      if(!attch || attch.IsRuined())return 0;
      if(slotname == "Mask" && attch.GetCompEM().IsWorking())return 1;
      for(int j=0;j<GetTZClothesConfigClient().TZListSlotProtection.Get(i).ListProtections.Count();j++)
      {
        if(attch.IsKindOf(GetTZClothesConfigClient().TZListSlotProtection.Get(i).ListProtections.Get(j).ClotheName))
        {
            protection = GetTZClothesConfigClient().TZListSlotProtection.Get(i).ListProtections.Get(j).Protection;
            #ifdef TZDEBUG
            GetTZLogger().LogInfo("GetProtectionLevel: protection"+protection.ToString());
            #endif
            return protection;
        }
      }
      return protection;
    }

    void GetToxicConfigResponse(CallType type,  ParamsReadContext ctx,  PlayerIdentity sender,  Object target)
    {
        if (!GetGame().IsClient())
            return;
        Param2<ref StaticToxicZoneLocationsClient, int> data;
        if (!ctx.Read(data))
            return;
        m_ToxicLocations = data.param1;
        NbSickGiven = data.param2;

        if(!HasStarted)
        StartRadCheck();
        #ifdef TZDEBUG
        GetTZLogger().LogInfo("GetToxicConfigResponse:StartRadCheck");
        #endif
    }

    void SendToxicZoneStatut( string name, bool rep)
    {
      #ifdef TZDEBUG
      GetTZLogger().LogInfo("SendToxicZoneStatut");
      #endif
      GetRPCManager().SendRPC("TZToxicZone", "GetToxicStatut",  new Param3<string,bool, bool>(name,rep,IsOnlyGasMask), true, NULL);
    }

    void SendSicknessAmount(float toxictogive)
    {
      #ifdef TZDEBUG
      GetTZLogger().LogInfo("SendSicknessAmount:"+toxictogive.ToString());
      #endif
      GetRPCManager().SendRPC("TZToxicZone", "GetSickQtyToGive", new Param1<float>(toxictogive), true);
    }
};
