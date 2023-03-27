class TZCrateSystem
{
	private EntityAI m_Loot=NULL;
	private ref array<EntityAI> m_LootList;
	private ref array<Object> DeadWolfObjs;

	void TZCrateSystem()
	{
		GetTZLogger().LogInfo("[LOOTSYSTEM]:LootSpawner - Started !");
		m_LootList = new array<EntityAI>;
		DeadWolfObjs = new array<Object>;

		if ( GetGame().IsServer() ) {
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.StartCrateSystem, 2000);
		}
	}

	void StartCrateSystem()
	{
		GetGame().GameScript.Call( this, "LootSpawner", null );
	}

	array<ref CrateLocation> GetArrayCratePositions(array<ref CrateLocation>crateslocations)
	{
		array<ref CrateLocation> CrateLocations = new array<ref CrateLocation>;
		for(int i =0;i<crateslocations.Count();i++)
		{
			CrateLocations.Insert(crateslocations.Get(i));
		}
		return CrateLocations;
	}

	void LootSpawner()
	{
		int m_delay = GetTZLootConfig().TimerLoot;
		if(!m_delay)return;
		int SpawnSeed = TZGetTimeStamp();
		Math.Randomize(SpawnSeed);
		while(1)
		{
			CheckDeadWolfStatus();
			CheckToxicChestListStatus();
			for( int i=0;i<GetSTZConfig().StaticToxicAreaLocation.Count();i++)
			{
				GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicZoneName:" + GetSTZConfig().StaticToxicAreaLocation.Get(i).ToxicZoneStatut + "- IsLootActive="+GetSTZConfig().StaticToxicAreaLocation.Get(i).IsLootActive.ToString());
				if(GetSTZConfig().StaticToxicAreaLocation.Get(i).IsLootActive == 1)
				{
					array<ref CrateLocation>m_tempCrateLocations = GetArrayCratePositions(GetSTZConfig().StaticToxicAreaLocation.Get(i).ToxicCratePosition);
					if(m_tempCrateLocations.Count()==0)continue;
				  GetTZLogger().LogInfo("[LOOTSYSTEM]: NumberOfCratePerTime: " + GetSTZConfig().StaticToxicAreaLocation.Get(i).NumbCratePerTime.ToString());
					for(int j=0; j< GetSTZConfig().StaticToxicAreaLocation.Get(i).NumbCratePerTime; j++)
					{
						if(m_tempCrateLocations.Count()==0)continue;
						GetTZLogger().LogInfo("Cases count:"+m_tempCrateLocations.Count().ToString());
						int fin=-1+m_tempCrateLocations.Count();
						int WhichZone=Math.RandomIntInclusive(0,fin);
						//GetTZLogger().LogInfo("fin = "+fin.ToString() + "-WhichZone:"+WhichZone.ToString() + "Crate pos:"+m_tempCrateLocations.Get(WhichZone).POS.ToString());
						StaticToxicZoneLocation TZL = GetSTZConfig().StaticToxicAreaLocation.Get(i);
						CheckForOldCrate(m_tempCrateLocations.Get(WhichZone).POS,TZL.ContainerName);
						CreateEzDrop(TZL.MaxLoot,TZL.ContainerName,m_tempCrateLocations.Get(WhichZone).POS, m_tempCrateLocations.Get(WhichZone).ORI,m_tempCrateLocations.Get(WhichZone).Name,i);
						m_tempCrateLocations.RemoveOrdered(WhichZone);
					}
				}
			}
			Sleep(m_delay);
		}
	}

	void CheckForOldCrate(vector pos, string name)
	{
		array<Object> ObjectArray = new array<Object>;
		GetGame().GetObjectsAtPosition3D(pos, 0.5, ObjectArray, NULL);
		if (ObjectArray.Count() < 1)return;

		for (int i = 0; i < ObjectArray.Count(); i++)
		{
			if(ObjectArray.Get(i).IsKindOf(name))
			{
				GetTZLogger().LogInfo("[LOOTSYSTEM]: A previous case has been found at that location and got deleted!");
				GetGame().ObjectDelete(ObjectArray.Get(i));
			}
		}
	}

	void CreateEzDrop(int maxloot, string container_name,vector v, vector o, string name,int here)
	{
		int k,temp;
		if(v[1]==0)v[1]=GetGame().SurfaceY(v[0], v[2]);
		m_Loot = EntityAI.Cast(GetGame().CreateObject( container_name, v, false, true, true));
		m_Loot.SetOrientation(o);
		m_LootList.Insert(m_Loot);
		GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicCase Spawned:"+" CaseName: "+ name + "- Position: X:"+v[0].ToString()+" Y:"+v[1].ToString()+" Z:"+v[2].ToString());
		int count=-1+GetTZLootConfig().ListLoots.Count();
		for(int i=0; i<=count;i++)
		{
			if(GetTZLootConfig().ListLoots.Get(i).Name==name){
				k=i;
			}
		}
		for(int l=0;l<GetTZLootConfig().ListLoots.Get(k).Loots.Count();l++)
		{
			if(temp>=maxloot && maxloot!=-1)continue;
			if ( GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).ProbToSpawn > Math.RandomFloatInclusive(0,1) )
			{
				if (GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Count() == 0)
				{
					m_Loot.GetInventory().CreateInInventory(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					temp+=1;
					GetTZLogger().LogInfo(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					continue;
				}
				else
				{
					m_Loot.GetInventory().CreateInInventory(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					temp+=1;
					GetTZLogger().LogInfo(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).LootName);
					for( int parc=0; parc < GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Count() ; parc++)
					{
						if ( GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).ProbAttachToSpawn > Math.RandomFloatInclusive(0,1) )
						{
							m_Loot.GetInventory().CreateInInventory(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).AttachName);
							temp+=1;
							GetTZLogger().LogInfo(GetTZLootConfig().ListLoots.Get(k).Loots.Get(l).AttachmentsToLoot.Get(parc).AttachName);
						}
					}
				}
			}
		}
		for(int j=0;j<GetSTZConfig().StaticToxicAreaLocation.Get(here).CreatureList.Count();j++)
		{
			int m_stop= -1 + GetSTZConfig().StaticToxicAreaLocation.Get(here).CreatureList.Get(j).Max;
			GetTZLogger().LogInfo("[LOOTSYSTEM] Spawned: " + GetSTZConfig().StaticToxicAreaLocation.Get(here).CreatureList.Get(j).CreatureName + "count: " + GetSTZConfig().StaticToxicAreaLocation.Get(here).CreatureList.Get(j).Max.ToString());
			for(int m_k=0;m_k<=m_stop;m_k++)
			{
				if(GetSTZConfig().StaticToxicAreaLocation.Get(here).CreatureList.Get(j).ProbToSpawn > Math.RandomFloatInclusive(0,1))
				{
					vector offset = v;
					offset[0] = offset[0] + Math.RandomIntInclusive(-20,20);
					offset[2] = offset[2] + Math.RandomIntInclusive(-20,20);
					string creature = GetSTZConfig().StaticToxicAreaLocation.Get(here).CreatureList.Get(j).CreatureName;
					Object Wolf=GetGame().CreateObject(creature, snapToGround(offset), false, true, true);
					DeadWolfObjs.Insert(Wolf);
				}
			}
		}
	}

	void CheckDeadWolfStatus()
	{
		GetTZLogger().LogInfo("[LOOTSYSTEM]: [CreatureCleaner] !");
		if(DeadWolfObjs.Count() == 0){
			GetTZLogger().LogInfo("[LOOTSYSTEM]: TZCreature equal to 0!");
            return;
        }
		else
		{
			for(int i = 0; i < DeadWolfObjs.Count(); i++){
				if(DeadWolfObjs.Get(i)!=NULL){
					GetGame().ObjectDelete(DeadWolfObjs.Get(i));
					GetTZLogger().LogInfo("[LOOTSYSTEM]: TZCreature has been deleted!");
				}
			}
			DeadWolfObjs.Clear();
			return;
		}

	}

	void CheckToxicChestListStatus()
	{
		GetTZLogger().LogInfo("[LOOTSYSTEM]: [ToxicChestCleaner] !");
		if(m_LootList.Count() == 0){
			GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicChestList equal to 0!");
            return;
        }
		else
		{
			for(int i = 0; i < m_LootList.Count(); i++){
				if(m_LootList.Get(i)!=NULL){
					GetGame().ObjectDelete(m_LootList.Get(i));
					GetTZLogger().LogInfo("[LOOTSYSTEM]: ToxicChestList has been deleted!");
				}
			}
			m_LootList.Clear();
			return;
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
}
