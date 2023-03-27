class TZSlotProtection
{
	string SlotName;
	ref array<ref TZProtectiveClothe>ListProtections;

	void TZSlotProtection(string slotname)
	{
		SlotName = slotname;
		ListProtections = new array<ref TZProtectiveClothe>;
	}

	void AddTZProtectiveClothe(string item_name, int protect_value)
	{
		ListProtections.Insert(new TZProtectiveClothe(item_name,protect_value));
	}
};

class TZProtectiveClothe
{
	string ClotheName;
	int    Protection;

	void TZProtectiveClothe(string clothename, int value)
	{
		ClotheName = clothename;
		Protection = value;
	}
};

class CrateLocation
{
    string Name;
    vector POS, ORI;

    void CrateLocation(string name, vector pos, vector ori)
	{
        Name = name;
        POS = pos;
        ORI = ori;
    }
}

class ParticleListe
{
	string NName;
	vector PPos;

	void ParticleListe(string name, vector pos)
	{
		NName=name;
		PPos=pos;
	}
}

class TZCreature{
	string CreatureName;
	int Max;
  float ProbToSpawn = 1.0;

	void TZCreature(string creaturename, int max, float probtospawn=1.0)
	{
		CreatureName = creaturename;
		Max = max;
    ProbToSpawn = probtospawn;
	}
}
