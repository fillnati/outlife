class TZMovingToxicZoneClient
{
	private string 		Coordinate;
	private vector 		SMOKE = "0 0 0";
	private House 		m_DynParticle;
	private int 			RestartMZ=0;
	private float 		CooX;
	private float 		CooY;
	private string 		Statut;
	private bool   		IsInside;
	private bool   		HasStarted=false;
	private int  			ClothesProtection=0;
	private int  			RequiredProtection = 1;
	private int  			NbSickGiven;
	private bool      IsLongParticle = false;
	private int       ParticleID;

	ref array<Particle> m_MovingParticles;

	private ref MovingToxicZoneLocation DynTZ;

	void TZMovingToxicZoneClient(MovingToxicZoneLocation dyntz, int delta_t)
	{
		GetTZLogger().LogInfo("TZMovingToxicZone - Started ! : ");
		m_MovingParticles = new array<Particle>;

		DynTZ=dyntz;
		NbSickGiven = DynTZ.NbSickGiven;
		CheckIfLongParticle(DynTZ.ParticleName);
		ParticleID = TZGetSmokeIDFromString(DynTZ.ParticleName);

		DefineRestartMZ(delta_t);
		StartParticleEffect(delta_t);

		HasStarted = true;
		//GetGame().GetMission().MissionScript.Call( this, "CheckScheduler", null );
		GetGame().GetMission().MissionScript.Call( this, "ZoneCheck", null );
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(CheckScheduler, 60000, true);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(RestartDynTZ, RestartMZ*1000, true);
	}

	void DefineRestartMZ(int delta_t)
	{
		RestartMZ=DynTZ.Norme/((Math.Sqrt(Math.Pow(DynTZ.Speed,2)))/60) - delta_t;
		GetTZLogger().LogInfo(DynTZ.MovingToxicZoneStatut+" RestartMZ: "+RestartMZ.ToString());
	}

	void RestartDynTZ()
	{
		   CooX=DynTZ.StartX;
		   CooY=DynTZ.StartY;
	}

	void StartParticleEffect(int delta_t)
	{
		CooX=DynTZ.StartX + (delta_t/60)*DynTZ.Speed;
		CooY=DynTZ.Coeff*CooX+DynTZ.YtoOrigin;
		SMOKE[0]=CooX;
		SMOKE[2]=CooY;
		SMOKE[1]=GetGame().SurfaceY( CooX, CooY );
		if(IsLongParticle)
		{
			for(int i = 0; i < 4;i++)
			{
				vector pos;
				pos[0] = SMOKE[0] + DynTZ.Radius*0.5*Math.Cos(i*3.14/2);
				pos[2] = SMOKE[2] + DynTZ.Radius*0.5*Math.Sin(i*3.14/2);
				pos[1] = SMOKE[1];
				Particle particle = Particle.PlayInWorld(ParticleID,pos);
				m_MovingParticles.Insert(particle);
			}
		}
		else
		{
			Particle particle2 = Particle.PlayInWorld(ParticleID,SMOKE);
			m_MovingParticles.Insert(particle2);
		}
	}

	private vector snapToGround(vector pos)
    {
        float pos_x = pos[0];
        float pos_z = pos[2];
        float pos_y = GetGame().SurfaceY( pos_x, pos_z );
        vector tmp_pos = Vector( pos_x, pos_y, pos_z );
        tmp_pos[1] = tmp_pos[1] + pos[1];

        return tmp_pos;
    }

	void CheckIfLongParticle(string name)
	{
		if(name.Contains("Long"))
		{
			IsLongParticle = true;
		}
	}

	void FunctionTrajectory()
	{
		//Print("FunctionTrajectory: Speed: "+DynTZ.Speed.ToString());
		//Print("FunctionTrajectory: Coeff: "+DynTZ.Coeff.ToString());
		//Print("FunctionTrajectory: YtoOrigin: "+DynTZ.YtoOrigin.ToString());
		CooX+=DynTZ.Speed;
		CooY=DynTZ.Coeff*CooX+DynTZ.YtoOrigin;
		//Print("CooY:"+CooY.ToString());
		//Print("CooX:"+CooX.ToString());
	}

	private void SendMessage(PlayerBase player, string message)
	{
		player.MessageAction(message);
	}

	private void SendPosToAdmin(PlayerBase pl)
	{
		//Steam 64 UID
		if (pl.IsMZAdmin)
		{
			Coordinate="Dyn.ToxicZone: X=" + CooX.ToString() + " Y=" + CooY.ToString();
			SendMessage(pl, Coordinate);
		}
	}

	void MoveParticles(float X,float Y)
	{
		SMOKE[0]=X;
		SMOKE[2]=Y;
		SMOKE[1]=GetGame().SurfaceY( X, Y );
		if(IsLongParticle)
		{
			for(int j = 0; j < 4;j++)
			{
				m_MovingParticles.Get(j).Stop();
			}
			m_MovingParticles.Clear();
			for(int i = 0; i < 4;i++)
			{
				vector pos;
				pos[0] = SMOKE[0] + DynTZ.Radius*0.5*Math.Cos(i*3.14/2);
				pos[2] = SMOKE[2] + DynTZ.Radius*0.5*Math.Sin(i*3.14/2);
				pos[1] = SMOKE[1];
				Particle particle = Particle.PlayInWorld(ParticleID,pos);
				m_MovingParticles.Insert(particle);
			}
		}
		else
		{
			m_MovingParticles.Get(0).Stop();
			Particle m_MovingParticle = Particle.PlayInWorld(ParticleID,SMOKE);
			m_MovingParticles.Clear();
			m_MovingParticles.Insert(m_MovingParticle);
		}

		Print("MoveParticle: "+SMOKE.ToString());
	}

	void CheckScheduler()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if(player)
		{
			FunctionTrajectory();
			MoveParticles(CooX,CooY);
			SendPosToAdmin(player);
			if(IsInside)
			{
				ProtectionCheckClient(player);
			}
		}
	}

	void ProtectionCheckClient(PlayerBase player)
	{
		ClothesCheckClient(player);

		#ifdef TZDEBUG
		GetTZLogger().LogInfo("ClothesProtection:" + ClothesProtection.ToString());
		#endif
		if(GetTZClothesConfigClient().RequiredProtection <= ClothesProtection )
		{
			return;
		}
		else
		{
			float toxictogive = 0;
			if(DynTZ.IsOnlyGasMask)
			{
				RequiredProtection = 1;
			}else RequiredProtection = GetTZClothesConfigClient().RequiredProtection;
			toxictogive += NbSickGiven*(1.0-ClothesProtection/RequiredProtection*1.0);

			#ifdef TZDEBUG
			GetTZLogger().LogInfo("toxictogive:" + toxictogive.ToString());
			#endif

			if(toxictogive == 0)return;
			GetToxicZoneClient().SendSicknessAmount(toxictogive);
		}
	}

	void ClothesCheckClient(PlayerBase player)
	{
			ClothesProtection=0;
			for (int i = 0; i <= -1 + GetTZClothesConfigClient().TZListSlotProtection.Count() ;i++)
			{
				EntityAI SuitsPart;
				string slotname = GetTZClothesConfigClient().TZListSlotProtection.Get(i).SlotName;
				SuitsPart = player.FindAttachmentBySlotName(slotname);
				ClothesProtection +=GetProtectionLevel(SuitsPart, i, slotname);
			}
	}

	float GetProtectionLevel(EntityAI attch, int i, string slotname)
	{
		int protection = 0;
		if(!attch || attch.IsRuined())return 0;
		if(slotname == "Mask" && attch.GetCompEM().IsWorking())return 1;
		for(int j=0;j<= -1 + GetTZClothesConfigClient().TZListSlotProtection.Get(i).ListProtections.Count();j++)
		{
			if(attch.IsKindOf(GetTZClothesConfigClient().TZListSlotProtection.Get(i).ListProtections.Get(j).ClotheName))
			{
					protection = GetTZClothesConfigClient().TZListSlotProtection.Get(i).ListProtections.Get(j).Protection;
					return protection;
			}
		}
		return protection;
	}

	void ZoneCheck()
	{
		while(1)
		{
			PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
			if(player)
			{
				MovingToxicZone(player);
			}
			else
			{
				delete this;
			}
			Sleep(2000);
		}
	}

	void MovingToxicZone(PlayerBase player)
	{
		GetTZLogger().LogInfo("MovingToxicZone - X: " + CooX.ToString() + " Y: " + CooY.ToString() + " Radius: " + DynTZ.Radius);
		vector pos = player.GetPosition();
		float distance_squared = Math.Pow(CooX-pos[0], 2) + Math.Pow(CooY-pos[2], 2);
		if ( distance_squared <= Math.Pow(DynTZ.Radius, 2) )
		{
			if (Statut!=DynTZ.MovingToxicZoneStatut && !IsInside)
			{
				Statut=DynTZ.MovingToxicZoneStatut;
				IsInside=true;
				SendToxicZoneStatut(Statut,IsInside);
				if(DynTZ.IsMsgActive==0)return;
				NotificationSystem.AddNotificationExtended( 5, "Toxic Zone", DynTZ.MsgEnterZone, "ToxicZone_Data/data/Logo/Toxic.paa");
			}
		}
		else
		{
			if (Statut==DynTZ.MovingToxicZoneStatut && IsInside)
			{
				SendToxicZoneStatut(Statut,false);
				Statut="";
				IsInside=false;
				if(DynTZ.IsMsgActive==0)return;
				NotificationSystem.AddNotificationExtended( 5, "Toxic Zone", DynTZ.MsgExitZone, "ToxicZone_Data/data/Logo/Toxic.paa");
			}
		}
	}

	void SendToxicZoneStatut( string name, bool rep)
	{
		#ifdef TZDEBUG
		GetTZLogger().LogInfo("SendToxicZoneStatut");
		#endif
		GetRPCManager().SendRPC("TZToxicZone", "GetToxicStatut",  new Param2<string,bool>(name,rep), true, NULL);
	}
}
