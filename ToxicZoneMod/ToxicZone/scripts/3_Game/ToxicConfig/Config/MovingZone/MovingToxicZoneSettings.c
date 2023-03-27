class MovingToxicAreaSettings
{
	bool 			IsMovingZoneActive;
	ref array<ref MovingToxicZoneLocation> MovingToxicAreaLocation;
	ref TStringArray AdminUID = new TStringArray;
	ref array<ref StaticToxicZoneLocation> StaticToxicAreaLocation;

	void MovingToxicAreaSettings() {
		MovingToxicAreaLocation = new array<ref MovingToxicZoneLocation>;
		StaticToxicAreaLocation = new array<ref StaticToxicZoneLocation>;
	}

	void DefaultConfig()
	{
		IsMovingZoneActive=true;
		AdminUID.Insert("76561198047475641");
		MovingToxicAreaLocation.Insert(new MovingToxicZoneLocation(50,true,"You're in a toxic area","You're in a toxic area",0.25,1,"GreenSmokeLong","ZelenToNovy",30,2000,5000,7442,8330,170));
		JsonFileLoader<MovingToxicAreaSettings>.JsonSaveFile(TZ_MZ_CONFIG, this);
	}

	void Save()
	{
		JsonFileLoader<MovingToxicAreaSettings>.JsonSaveFile(TZ_MZ_CONFIG, this);
	}

	static ref MovingToxicAreaSettings Load()	{
		MovingToxicAreaSettings settings = new MovingToxicAreaSettings();

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

		if (FileExist(TZ_MZ_CONFIG)) {
			JsonFileLoader<MovingToxicAreaSettings>.JsonLoadFile(TZ_MZ_CONFIG, settings);
		}else settings.DefaultConfig();

		return settings;
	}
}
