class StaticToxicZoneLocation
{
  string ToxicZoneStatut;
  float X, Y, Radius;
  float X1,Y1,X2,Y2;
  bool IsSquareZone;
  bool IsMsgActive;
  string MsgEnterZone;
  string MsgExitZone;
  bool IsOnlyGasMask;
  bool IsLootActive;
	string ContainerName;
  int NumbCratePerTime;
	int  MaxLoot;
  ref array<ref ParticleListe> ParticlesPosition;
	ref array<ref CrateLocation> ToxicCratePosition;
	ref array<ref TZCreature> CreatureList;

    void StaticToxicZoneLocation(string toxiczonestatut, float x, float y, float radius,float x1, float y1, float x2, float y2,bool isquarezone,bool isonlygasmask, bool islootactive,string container_name, int ncpt, int maxloot)
	  {
        ToxicCratePosition = new array<ref CrateLocation>;
        ParticlesPosition = new array<ref ParticleListe>;
        CreatureList = new array<ref TZCreature>;
    		MaxLoot=maxloot;
    		IsOnlyGasMask=isonlygasmask;
    		IsSquareZone=isquarezone;
    		ContainerName=container_name;
    		IsLootActive=islootactive;
    		NumbCratePerTime=ncpt;
        ToxicZoneStatut = toxiczonestatut;
        X=x;
        Y=y;
    		X1=x1;
    		Y1=y1;
    		X2=x2;
    		Y2=y2;
        Radius = radius;
        IsMsgActive = true;
        MsgEnterZone = "You're in a toxiczone";
        MsgExitZone = "You're in leaving a toxiczone";
    }

	void AddCratePosition(string name, vector pos, vector ori)
	{
		ToxicCratePosition.Insert(new ref CrateLocation(name,pos,ori));
	}

	void AddParticlePosition(string name, vector pos)
	{
		ParticlesPosition.Insert(new ref ParticleListe(name,pos));
	}

	void AddCreatureToList(string name, int max, float probtospawn)
	{
		CreatureList.Insert(new ref TZCreature(name,max,probtospawn));
	}
}
