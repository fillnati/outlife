class StaticToxicAreaSettings
{
	bool			IsToxicZoneActive;
	ref array<ref StaticToxicZoneLocation> StaticToxicAreaLocation;

	void StaticToxicAreaSettings() {
		StaticToxicAreaLocation = new array<ref StaticToxicZoneLocation>;
	}

	void StaticDefaultConfig()
	{
		IsToxicZoneActive = true;
		StaticToxicAreaLocation = new array<ref StaticToxicZoneLocation>;
		StaticToxicAreaLocation.Insert(new StaticToxicZoneLocation("TZKamensk", 7890, 14697, 300, -1,-1,-1,-1,false,false,true,"ToxicCase",1,8));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(8010, 0, 14625));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7794, 0, 14788));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7871, 0, 14700));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7691, 0, 14855));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7904, 0, 14585));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7814, 0, 14542));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7766, 0, 14639));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7725, 0, 14706));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(8019, 0, 14758));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7644, 0, 14750));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7910, 0, 14724));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(7916, 0, 14627));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(8115, 0, 14563));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(8161, 0, 14706));
		StaticToxicAreaLocation[0].AddParticlePosition("GreenSmoke",Vector(8003, 0, 14538));
		StaticToxicAreaLocation[0].AddCreatureToList("Animal_CanisLupus_Grey",7,1);
		StaticToxicAreaLocation[0].AddCreatureToList("Animal_UrsusArctos",1,1);
		StaticToxicAreaLocation.Insert(new StaticToxicZoneLocation("TZTisy", 1655, 14068, 600,-1,-1,-1,-1,false,false,true,"ToxicCase",1,8));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1647.65, 451.73, 14193.56));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1660.05, 451.753174, 14362.29));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1811.86, 449.522156, 14249.54));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1482.53, 462.749481, 14415.65));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1558.28, 452.769989, 14066.50));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1764.74, 450.321228, 14057.13));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1721.75, 445.441315, 13882.53));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1471.98, 473.016602, 14243.73));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1647.90, 451.226593, 13994.00));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1870.52, 432.152893, 13778.73));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1740.96, 433.674072, 13654.42));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1510.25, 439.791687, 13603.59));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1402.81, 449.132599, 13687.34));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1340.24, 463.932831, 14049.60));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1264.25, 462.461884, 14009.88));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1058.68, 470.137817, 13907.31));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1635.71, 443.326294, 13750.46));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1534.73, 455.118683, 13779.95));
		StaticToxicAreaLocation[1].AddParticlePosition("GreenSmoke",Vector(1509.31, 456.668396, 13892.94));
		StaticToxicAreaLocation[1].AddCreatureToList("Animal_CanisLupus_Grey",7,1);
		StaticToxicAreaLocation[1].AddCreatureToList("Animal_UrsusArctos",1,1);
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1386.162231, 464.568634, 14422.077148),Vector(115.000000, 0.000000, -0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1380.556763, 464.443634, 14427.786133),Vector(115.000000, 0.000000, -0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1694.400024, 448.402832, 14210.000000),Vector(-108.000000, 0.000000, -0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1396.583740, 464.579834, 14450.625977),Vector(115.000000, 0.000000, -0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1390.250244, 464.568634, 14428.591797),Vector(115.000000, 0.000000, -0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1696.090210, 456.484650, 14179.058594),Vector(73.000000, 0.000000, 0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1705.524048, 456.484650, 14167.800781),Vector(-110.000000, 0.000000, 0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1705.130005, 452.414673, 14171.078125),Vector(-20.000000, -0.000003, 0.000002));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1534.478516, 452.700958, 14176.821289),Vector(111.492668, 0.000000, 0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1674.708862, 445.624695, 13883.582031),Vector(-59.999996, 0.000000, 0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1678.462402, 445.741333, 13823.817383),Vector(34.000000, 0.000000, 0.000000));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1722.444092, 451.940338, 13721.448242),Vector(125.000000, -0.005424, 0.004700));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1896.774902, 448.957642, 13707.833008),Vector(-134.000000, -0.083319, -0.042664));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1888.663452, 449.046387, 13704.051758),Vector(45.000000, -0.031207, -0.014148));
		StaticToxicAreaLocation[1].AddCratePosition("Army1",Vector(1991.667847, 450.258240, 13825.063477),Vector(-179.999985, -0.083759, 0.079992));
		StaticToxicAreaLocation[1].AddCratePosition("Army2",Vector(1988.597778, 450.254089, 13817.044922),Vector(0.000000, -0.002396, -0.006766));
		StaticToxicAreaLocation[0].AddCratePosition("Army1",Vector(8029.16339,  339.823090, 14642.799805),Vector(-90.000000, 0.000000, 0.000000));
		StaticToxicAreaLocation[0].AddCratePosition("Army2",Vector(8028.430176, 339.823090, 14642.799805),Vector(-90.000000, 0.000000, 0.000000));
		StaticToxicAreaLocation[0].AddCratePosition("Army1",Vector(7812.989258, 356.012085, 14783.941406),Vector(50.000004, 0.386834, 1.181611));
		StaticToxicAreaLocation[0].AddCratePosition("Army2",Vector(7832.350586, 357.100006, 14793.992188),Vector(-176.000000, 0.000000, -9.000000));
		StaticToxicAreaLocation[0].AddCratePosition("Army1",Vector(7895.693359, 344.399994, 14680.602539),Vector(-150.000000, 3.204192, -9.829134));
		StaticToxicAreaLocation[0].AddCratePosition("Army2",Vector(7903.302734, 339.049988, 14637.416016),Vector(-80.000000, 6.000000, 0.000000));
		StaticToxicAreaLocation[0].AddCratePosition("Army1",Vector(8040.299805, 340.251709, 14611.299805),Vector(145.000000, -0.365324, 1.120535));
		StaticToxicAreaLocation[0].AddCratePosition("Army2",Vector(7928.899902, 340.477814, 14670.049805),Vector(21.534840, 0.493056, 2.382456));
		StaticToxicAreaLocation[0].AddCratePosition("Army1",Vector(8010.200195, 340.287964, 14654.200195),Vector(150.000000, 0.153955, -1.174890));
		JsonFileLoader<StaticToxicAreaSettings>.JsonSaveFile(TZ_STATIC_CONFIG, this);
	}

	void Save()
	{
			JsonFileLoader<StaticToxicAreaSettings>.JsonSaveFile(TZ_STATIC_CONFIG, this);
	}

	static ref StaticToxicAreaSettings Load()	{
		 StaticToxicAreaSettings settings = new StaticToxicAreaSettings();

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

		if (FileExist(TZ_STATIC_CONFIG)) {
			JsonFileLoader<StaticToxicAreaSettings>.JsonLoadFile(TZ_STATIC_CONFIG, settings);
		}
		else
		{
			settings.StaticDefaultConfig();
		}

		return settings;
	}
}
