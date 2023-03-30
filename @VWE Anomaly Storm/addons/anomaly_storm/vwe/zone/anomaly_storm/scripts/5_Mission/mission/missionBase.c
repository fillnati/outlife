modded class MissionBase
{
	void MissionBase()
	{
		if ( !GetGame().IsMultiplayer() )
		{
			m_WorldLighting = new WorldLighting;
		}
	}
}