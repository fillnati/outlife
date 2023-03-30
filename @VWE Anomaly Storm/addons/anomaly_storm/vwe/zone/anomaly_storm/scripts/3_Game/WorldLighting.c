modded class WorldLighting
{
	const string	lighting_radstorm			= "vwe\\zone\\anomaly_storm\\lighting\\anomaly_storm_rad.lighting";
	private int		m_currentLightingID;
	
	void WorldLighting()
	{
		m_currentLightingID = 0;
	}
	
	override void SetGlobalLighting( int lightingID )
	{
		switch ( lightingID )
		{
			case 0:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_default );
				break;
				
			case 1:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_darknight );
				break;
				
			case 2:
				GetGame().GetWorld().LoadNewLightingCfg( lighting_radstorm );
				break;
			
			default:
				Print( "Unknown global lighting ID received from the server." );
				return;
		}
		
		m_currentLightingID = lightingID;
	}
	
	int GetGlobalLightingID()
	{
		return m_currentLightingID;
	}
}