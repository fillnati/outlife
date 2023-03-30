class ZoneRadioBase extends House
{
	protected PluginZoneBroadcasting	m_pluginZoneBroadcasting;
	protected string					m_noiseSoundSet;
	protected EffectSound				m_noiseSoundLoop;
	protected EffectSound				m_broadcastSound;
	protected float						m_soundMaxVolume;
	
	void ZoneRadioBase()
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			m_pluginZoneBroadcasting = PluginZoneBroadcasting.Cast( GetPlugin(PluginZoneBroadcasting) );
			if (m_pluginZoneBroadcasting)
				m_pluginZoneBroadcasting.AddZoneRadio(this);
			
			m_noiseSoundLoop = null;
			m_noiseSoundSet = "personalradio_staticnoise_SoundSet";
			m_soundMaxVolume = 1.0;
			
			Init();
			
			SoundNoiseStart();
		}
	}
	
	void ~ZoneRadioBase()
	{
		if ( GetGame() )
		{
			StopBroadcastSound();
			SoundNoiseStop();
			if (m_pluginZoneBroadcasting)
				m_pluginZoneBroadcasting.RemoveZoneRadio(this);
		}
	}
	
	protected void Init() {}
	
	void PlayBroadcastSound(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{			
			PlaySoundSet(m_broadcastSound, soundSet, fadeIn, fadeOut, loop);
			if (m_broadcastSound)
			{
				m_broadcastSound.SetSoundMaxVolume(m_soundMaxVolume);
			}
		}
	}
	
	void StopBroadcastSound()
	{
		StopSoundSet( m_broadcastSound );
	}
	
	protected void SoundNoiseStart()
	{
		if (m_noiseSoundLoop)
			return;
		
		PlaySoundSetLoop( m_noiseSoundLoop, m_noiseSoundSet, 0.0, 0.0 );
		if (m_noiseSoundLoop)
		{
			m_noiseSoundLoop.SetSoundMaxVolume(m_soundMaxVolume);
		}
	}

	protected void SoundNoiseStop()
	{
		StopSoundSet( m_noiseSoundLoop );
	}	
}