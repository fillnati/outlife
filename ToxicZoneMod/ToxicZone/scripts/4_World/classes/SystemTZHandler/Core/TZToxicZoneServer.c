class TZToxicZoneServer
{
  ref StaticToxicZoneLocationsClient m_ToxicLocations;
  private ref array<House> m_Particle = new array<House>;

  void TZToxicZoneServer()
  {
      GetTZLogger().LogInfo("TZToxicZoneServer - Started");
      GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitTZToxicZoneServer, 1000);
  }

  void InitTZToxicZoneServer()
  {
    //We convert our radzone config so we can send it to client
    m_ToxicLocations = new StaticToxicZoneLocationsClient(GetSTZConfig().StaticToxicAreaLocation);
    SpawnParticles();
  }


  void SpawnParticles()
  {
    GetTZLogger().LogInfo("[TZ STATIC TOXICZONE] - StartParticles");
    for( int i = 0;i<GetSTZConfig().StaticToxicAreaLocation.Count();i++)
    {
      StaticToxicZoneLocation ToxArea = GetSTZConfig().StaticToxicAreaLocation.Get(i);

      for (int k=0;k<ToxArea.ParticlesPosition.Count();k++)
      {
        //GetTZLogger().LogInfo("[TZ STATIC TOXICZONE] - Spawned particle");
        vector pos = ToxArea.ParticlesPosition.Get(k).PPos;
        pos = snapToGround(pos);
        m_Particle.Insert(House.Cast(GetGame().CreateObject(ToxArea.ParticlesPosition.Get(k).NName,pos)));
      }
    }
  }

   private vector snapToGround(vector pos)
    {
        if(pos[1]>0)return pos;
        float pos_x = pos[0];
        float pos_z = pos[2];
        float pos_y = GetGame().SurfaceY( pos_x, pos_z );
        vector tmp_pos = Vector( pos_x, pos_y, pos_z );
        tmp_pos[1] = tmp_pos[1] + pos[1];

        return tmp_pos;
    }

  void  ~TZToxicZoneServer()
  {

  }

  void SendTZConfigToClient(PlayerIdentity sender)
  {
      if(m_ToxicLocations)
      {
          GetRPCManager().SendRPC("TZToxicZone", "GetToxicConfigResponse", new Param2<ref StaticToxicZoneLocationsClient, int>(m_ToxicLocations,GetTZGNRConfig().NbSickGiven), true, sender);
      }
  }

  //-----------------------------------RPC called on server-------------------------------------//
  void GetToxicStatut(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
  {
   if (!GetGame().IsServer())
     return;

    Param3<string, bool, bool> data;
     if (!ctx.Read(data))
       return;

     PlayerBase player = TZGetPlayerByIdentity(sender);
     player.IsInside.TZName = data.param1;
     player.IsInside.TZStatut = data.param2;

     if(player.IsInside.TZStatut)
     {
       player.SetToxicDamageOnClothes(data.param3);
     }

     #ifdef TZDEBUG
     GetTZLogger().LogInfo("[ToxicStatut] : PlayerName:"+ sender.GetName() + " Name:"+data.param1 + " Statut:"+data.param2);
     #endif
  }

  void GetSickQtyToGive(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
  {
   if (!GetGame().IsServer())
     return;

    Param1<float> data;
     if (!ctx.Read(data))
       return;
     PlayerBase player = TZGetPlayerByIdentity(sender);
     player.GiveToxicSickness(data.param1);
     player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);

     #ifdef TZDEBUG
     GetTZLogger().LogInfo("GetSickQtyToGive");
     #endif
  }
  //---------------------------------------------------------------------------------------------------------//
};
