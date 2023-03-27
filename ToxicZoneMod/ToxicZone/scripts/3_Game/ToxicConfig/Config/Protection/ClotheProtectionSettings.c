class TZClotheProtectionSettings
{
	int RequiredProtection;
	ref array<ref TZSlotProtection> TZListSlotProtection;

	void TZClotheProtectionSettings() {
		TZListSlotProtection = new  array<ref TZSlotProtection>;
	}

	void ClotheProtectionDefaultSettings()
	{
		RequiredProtection = 6;
		TZListSlotProtection.Insert(new  TZSlotProtection("Mask"));
		TZListSlotProtection.Get(0).AddTZProtectiveClothe("GP5GasMask",0);
		TZListSlotProtection.Insert(new  TZSlotProtection("Headgear"));
		TZListSlotProtection.Get(1).AddTZProtectiveClothe("NBCHoodBase",1);
		TZListSlotProtection.Insert(new  TZSlotProtection("Body"));
		TZListSlotProtection.Get(2).AddTZProtectiveClothe("NBCJacketBase",1);
		TZListSlotProtection.Insert(new  TZSlotProtection("Gloves"));
		TZListSlotProtection.Get(3).AddTZProtectiveClothe("NBCGloves_ColorBase",1);
		TZListSlotProtection.Insert(new  TZSlotProtection("Legs"));
		TZListSlotProtection.Get(4).AddTZProtectiveClothe("NBCPantsBase",1);
		TZListSlotProtection.Insert(new  TZSlotProtection("Feet"));
		TZListSlotProtection.Get(5).AddTZProtectiveClothe("NBCBootsBase",1);
		JsonFileLoader<TZClotheProtectionSettings>.JsonSaveFile(TZ_CP_CONFIG, this);
	}

	void AddTZListSlotProtection(string slotname)
	{
		TZListSlotProtection.Insert(new  TZSlotProtection(slotname));
	}

	void AddTZProtectiveClothes( array<string> clothes, array<int>protections)
	{
		for(int i = 0;i<clothes.Count();i++)
		{
			int k = -1 + TZListSlotProtection.Count();
			TZListSlotProtection.Get(k).AddTZProtectiveClothe(clothes.Get(i),protections.Get(i));
		}
	}

	static ref TZClotheProtectionSettings Load()	{
		 TZClotheProtectionSettings settings = new TZClotheProtectionSettings();

		if ( !FileExist( TZ_CONFIG_ROOT_SERVER ) )
		{
			MakeDirectory( TZ_CONFIG_ROOT_SERVER );
			if ( !FileExist( TZ_CONFIG_DIR_SERVER ) )
			{
				MakeDirectory( TZ_CONFIG_DIR_SERVER );
			}
			if ( !FileExist( TZ_LOGGER_DIR_SERVER ) )
			{
				MakeDirectory( TZ_LOGGER_DIR_SERVER );
			}
		}

		if (FileExist(TZ_CP_CONFIG)) {
			JsonFileLoader<TZClotheProtectionSettings>.JsonLoadFile(TZ_CP_CONFIG, settings);
		}
		else {
			settings.ClotheProtectionDefaultSettings();
		}

		return settings;
	}
};
