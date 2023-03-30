modded class Land_Lamp_City1_amp
{
	protected PluginZoneBroadcasting	m_pluginZoneBroadcasting;
	protected EffectSound				m_broadcastSound;
	protected vector					m_ampLocalPosition;
	
	void Land_Lamp_City1_amp()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_pluginZoneBroadcasting = PluginZoneBroadcasting.Cast( GetPlugin(PluginZoneBroadcasting) );
			if (m_pluginZoneBroadcasting)
				m_pluginZoneBroadcasting.AddPASReceiver(this);
		
			m_ampLocalPosition = "-0.725 7.632 2.920";
		}
	}
	
	void ~Land_Lamp_City1_amp()
	{
		if ( GetGame() && ( !GetGame().IsMultiplayer() || GetGame().IsClient() ) && m_pluginZoneBroadcasting )
		{
			StopBroadcastSound();
			m_pluginZoneBroadcasting.RemovePASReceiver(this);
		}
	}
	
	void PlayBroadcastSound(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			if ( m_broadcastSound )
			{
				StopBroadcastSound();
			}
			
			m_broadcastSound = SEffectManager.PlaySound( soundSet, this.GetPosition() + m_ampLocalPosition, fadeIn, fadeOut, loop );
			m_broadcastSound.SetSoundAutodestroy( true );
		}
	}
	
	void StopBroadcastSound()
	{
		if ( m_broadcastSound )
		{
			m_broadcastSound.SoundStop();
			m_broadcastSound = NULL;
		}
	}
}