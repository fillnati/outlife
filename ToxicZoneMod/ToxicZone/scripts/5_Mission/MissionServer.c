modded class MissionServer extends MissionBase
{
	void MissionServer()
	{
		m_TZToxicZoneCore = NULL;
		GetTZToxicZoneCore();
	}

	void ~MissionServer() {
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
	{
		super.InvokeOnConnect(player,identity);
		InitializeTZConfigToPlayer(player,identity);
	}

	void InitializeTZConfigToPlayer(PlayerBase player, PlayerIdentity identity)
	{
		#ifdef TZDEBUG
		GetTZLogger().LogInfo("Start - InitializeConfigToPlayer");
		#endif
		player.GP5DamageGrenade = GetTZGNRConfig().GP5DamageGrenade;
		//GetTZLogger().LogInfo("GP5DamageGrenade"+player.GP5DamageGrenade.ToString());
		player.NbSickGivenforToxicSmoke = GetTZGNRConfig().NbSickGivenforToxicSmoke;
		//GetTZLogger().LogInfo("NbSickGivenforToxicSmoke:"+player.NbSickGivenforToxicSmoke.ToString());
		GetTZToxicZoneCore().TransfertClotheProtectionConfigToClient(identity);

		if(GetSTZConfig().IsToxicZoneActive)
		{
			GetTZToxicZoneCore().m_TZToxicZoneServer.SendTZConfigToClient(identity);
		}
		if(GetMTZConfig().IsMovingZoneActive)
		{
			GetTZToxicZoneCore().SendMovingToxicZoneConfig(identity);
			for(int i=0;i<GetMTZConfig().AdminUID.Count();i++)
			{
				if (identity.GetPlainId() == GetMTZConfig().AdminUID.Get(i))
				{
					player.SetIsMZAdmin(true);
				}
			}
		}

		#ifdef TZDEBUG
		GetTZLogger().LogInfo("End - InitializeConfigToPlayer");
		#endif
	}


	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;

		//super.CreateCharacter(identity,pos,ctx,characterName);
	}

};
