static ref TZLogger g_TZLogger;
static TZLogger GetTZLogger(){
	if (!g_TZLogger) {
		g_TZLogger = new TZLogger();
	}
	return g_TZLogger;
}

static ref TZToxicZoneCore m_TZToxicZoneCore;
static TZToxicZoneCore GetTZToxicZoneCore() {
	if ( !m_TZToxicZoneCore ) {
		m_TZToxicZoneCore = new TZToxicZoneCore;
	}
	return m_TZToxicZoneCore;
}

static ref TZToxicZoneClient GetToxicZoneClient(){
	return GetTZToxicZoneCore().m_TZToxicZoneClient;
}

static ref LootTZSettings GetTZLootConfig(){
	return GetTZToxicZoneCore().m_ActiveLootSettings;
}

static ref GeneralToxicZoneSettings GetTZGNRConfig(){
	return GetTZToxicZoneCore().m_ActiveGeneralToxicZoneSettings;
}

static ref StaticToxicAreaSettings GetSTZConfig(){
	return GetTZToxicZoneCore().m_ActiveStaticToxicAreaSettings;
}

static ref MovingToxicAreaSettings GetMTZConfig(){
	return GetTZToxicZoneCore().m_ActiveMovingToxicAreaSettings;
}

static ref TZClotheProtectionSettings GetTZClothesConfigClient()	{
	return GetTZToxicZoneCore().m_TZClotheProtectionSettingsClient;
}

static PlayerBase TZGetPlayerByIdentity(PlayerIdentity sender)
{
	int	low	 =	0;
	int	high =	0;
	GetGame().GetPlayerNetworkIDByIdentityID( sender.GetPlayerId(), low, high );
	return PlayerBase.Cast( GetGame().GetObjectByNetworkId(low, high ));
}

static int TZGetSmokeIDFromString(string smokename)
{
	if(smokename.Contains("Long"))
	{
		smokename.Replace("Long","");
	}

	switch(smokename)
	{
		case "GreenSmoke": return ParticleList.TOXICZONE_GREENSMOKE;
		break;
		case "BlueSmoke": return ParticleList.TOXICZONE_BLUESMOKE;
		break;
		case "RedSmoke": return ParticleList.TOXICZONE_REDSMOKE;
		break;
		case "GreenSmoke2": return ParticleList.TOXICZONE_GREENSMOKE2;
		break;
		case "MustardSmoke": return ParticleList.TOXICZONE_MUSTARDSMOKE;
		break;
		case "WhiteSmoke": return ParticleList.TOXICZONE_WHITESMOKE;
		break;
		case "PurpleSmoke": return ParticleList.TOXICZONE_PURPLESMOKE;
		break;
		case "GreenSpore": return ParticleList.TOXICZONE_GREENSPORE;
		break;
		case "BlueSpore": return ParticleList.TOXICZONE_BLUESPORE;
		break;
		case "RedSpore": return ParticleList.TOXICZONE_REDSPORE;
		break;
		case "MustardSpore": return ParticleList.TOXICZONE_MUSTARDSPORE;
		break;
		case "WhiteSpore": return ParticleList.TOXICZONE_WHITESPORE;
		break;
		case "PurpleSpore": return ParticleList.TOXICZONE_PURPLESPORE;
		break;
		default:return ParticleList.TOXICZONE_GREENSMOKE;
		break;
	}
	return ParticleList.TOXICZONE_GREENSMOKE;
}

static int TZGetTimeStamp()
{
	int year, month, day, hour, minute, second;
	GetHourMinuteSecondUTC(hour, minute, second);
	GetYearMonthDayUTC(year, month, day);
	return JMDate.Timestamp(year,month,day,hour,minute,second);
}
