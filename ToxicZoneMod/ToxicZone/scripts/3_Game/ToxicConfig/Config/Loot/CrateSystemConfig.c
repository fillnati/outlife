class LootConfig
{
	string LootName;
	float  ProbToSpawn;
	ref array<ref AttachmentConfig> AttachmentsToLoot;
	//AttachmentsToItem = NULL;


	void LootConfig(string lootname, float probtospawn)
	{
		LootName = lootname;
		ProbToSpawn = probtospawn;
		AttachmentsToLoot = new array< ref AttachmentConfig>;
	}

	void AddAttachmentsToItem(string name, float prob)
	{
		AttachmentsToLoot.Insert(new AttachmentConfig(name,prob));
	}
}

class AttachmentConfig
{
	string AttachName;
	float  ProbAttachToSpawn;

	void  AttachmentConfig(string attachname, float probattachtospawn)
	{
		AttachName = attachname;
		ProbAttachToSpawn = probattachtospawn;
	}
}

class ListLootConfig{
	string Name;
	ref array<ref LootConfig> Loots;

	void ListLootConfig(string name)
	{
		Loots= new array<ref LootConfig>;
		Name=name;
	}

	void AddLootConfig(string lootname, float probtospawn)
	{
		Loots.Insert(new LootConfig(lootname,probtospawn));
	}
}

class LootTZSettings{

	int 			TimerLoot;
	bool			IsActive;
	ref array<ref ListLootConfig>ListLoots;

	void LootTZSettings() {
		ListLoots = new array<ref ListLootConfig>;
	}

	void LootTZSettingsDefaultSettings()	{
		IsActive=1;
		TimerLoot=2700000;
		ListLoots.Insert(new ListLootConfig("Army1"));
		ListLoots.Get(0).AddLootConfig("AKM",0.6);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("Mag_AKM_30Rnd",0.5);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("Mag_AKM_30Rnd",0.5);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("PSO1Optic",0.5);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("Mag_AKM_Drum75Rnd",0.2);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_Suppressor",0.3);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_PlasticHndgrd",0.85);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_RailHndgrd_Black",0.85);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_Bayonet",0.4);
		ListLoots.Get(0).Loots.Get(0).AddAttachmentsToItem("AK_FoldingBttstck_Black",0.6);
		ListLoots.Get(0).AddLootConfig("M4A1",0.6);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("Mag_STANAG_30Rnd",0.5);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("Mag_STANAGCoupled_30Rnd",0.3);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("ACOGOptic",0.4);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_CarryHandleOptic",0.6);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_CQBBttstck",0.7);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_MPBttstck",0.4);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_MPHndgrd",0.7);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_RISHndgrd",0.5);
		ListLoots.Get(0).Loots.Get(1).AddAttachmentsToItem("M4_Suppressor",0.4);
		ListLoots.Get(0).AddLootConfig("ToxicCure",0.7);
		ListLoots.Get(0).AddLootConfig("AmmoBox_545x39_20Rnd",0.8);
		ListLoots.Get(0).AddLootConfig("AmmoBox_556x45_20Rnd",0.8);
		ListLoots.Get(0).AddLootConfig("AmmoBox_762x39_20Rnd",0.8);
		ListLoots.Get(0).AddLootConfig("AmmoBox_762x54_20Rnd",0.8);
		ListLoots.Insert(new ListLootConfig("Army2"));
		ListLoots.Get(1).AddLootConfig("SVD",0.4);
		ListLoots.Get(1).Loots.Get(0).AddAttachmentsToItem("PSO1Optic",0.35);
		ListLoots.Get(1).Loots.Get(0).AddAttachmentsToItem("Mag_SVD_10Rnd",0.5);
		ListLoots.Get(1).AddLootConfig("AK74",0.6);
		ListLoots.Get(1).Loots.Get(1).AddAttachmentsToItem("AK_RailHndgrd_Black",0.7);
		ListLoots.Get(1).Loots.Get(1).AddAttachmentsToItem("AK74_WoodBttstck",0.7);
		ListLoots.Get(1).Loots.Get(1).AddAttachmentsToItem("AK_Bayonet",0.6);
		ListLoots.Get(1).Loots.Get(1).AddAttachmentsToItem("AK_FoldingBttstck_Black",0.7);
		ListLoots.Get(1).Loots.Get(1).AddAttachmentsToItem("AK_Suppressor",0.45);
		ListLoots.Get(1).Loots.Get(1).AddAttachmentsToItem("Mag_AK74_30Rnd",0.6);
		ListLoots.Get(1).AddLootConfig("FAL",0.3);
		ListLoots.Get(1).Loots.Get(2).AddAttachmentsToItem("Fal_FoldingBttstck",0.85);
		ListLoots.Get(1).Loots.Get(2).AddAttachmentsToItem("Fal_OeBttstck",0.75);
		ListLoots.Get(1).Loots.Get(2).AddAttachmentsToItem("Mag_FAL_20Rnd",0.6);
		ListLoots.Get(1).Loots.Get(2).AddAttachmentsToItem("ACOGOptic",0.45);
		ListLoots.Get(1).AddLootConfig("ToxicCure",0.7);
		ListLoots.Get(1).AddLootConfig("AmmoBox_545x39_20Rnd",0.8);
		ListLoots.Get(1).AddLootConfig("AmmoBox_556x45_20Rnd",0.8);
		ListLoots.Get(1).AddLootConfig("AmmoBox_762x39_20Rnd",0.8);
		ListLoots.Get(1).AddLootConfig("AmmoBox_762x54_20Rnd",0.8);
		JsonFileLoader<LootTZSettings>.JsonSaveFile(TZ_LOOT_CONFIG, this);
	}

	void Save()
	{
		JsonFileLoader<LootTZSettings>.JsonSaveFile(TZ_LOOT_CONFIG, this);
	}

	static ref LootTZSettings Load()	{
		ref LootTZSettings settings = new LootTZSettings();

		if (FileExist(TZ_OLD_LOOT_CONFIG)) {
			JsonFileLoader<LootTZSettings>.JsonLoadFile(TZ_OLD_LOOT_CONFIG, settings);
			settings.Save();
			bool attempt = DeleteFile(TZ_OLD_LOOT_CONFIG);
			return settings;
		}

		if (FileExist(TZ_LOOT_CONFIG)) {
			JsonFileLoader<LootTZSettings>.JsonLoadFile(TZ_LOOT_CONFIG, settings);
		}
		else {
			settings.LootTZSettingsDefaultSettings();
		}

		return settings;
	}
}
