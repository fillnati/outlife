class GeneralToxicZoneSettings
{
	int 			ToxicBloodLoss;
	int 			NbSickGiven;
	int 			SuitsDamage;
	int 			GP5DamageGrenade;
	int 			NbSickGivenforToxicSmoke;

	void DefaultConfig()
	{
		ToxicBloodLoss = 5;
	  NbSickGiven = 34;
		SuitsDamage = 20;
		GP5DamageGrenade = 20;
		NbSickGivenforToxicSmoke = 51;
		JsonFileLoader<GeneralToxicZoneSettings>.JsonSaveFile(TZ_GNRL_CONFIG, this);
	}

	void Save()
	{
		JsonFileLoader<GeneralToxicZoneSettings>.JsonSaveFile(TZ_GNRL_CONFIG, this);
	}

	void AdaptConfig()
	{
		if(ToxicBloodLoss == 5)
		{
			ToxicBloodLoss = 50;
		}
		JsonFileLoader<GeneralToxicZoneSettings>.JsonSaveFile(TZ_GNRL_CONFIG, this);
	}

	static ref GeneralToxicZoneSettings Load()	{
		ref GeneralToxicZoneSettings settings = new GeneralToxicZoneSettings();

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

		if (FileExist(TZ_GNRL_CONFIG)) {
		   JsonFileLoader<GeneralToxicZoneSettings>.JsonLoadFile(TZ_GNRL_CONFIG, settings);
			 settings.AdaptConfig();
		}else
		{
			settings.DefaultConfig();
		}

		return settings;
	}
}
