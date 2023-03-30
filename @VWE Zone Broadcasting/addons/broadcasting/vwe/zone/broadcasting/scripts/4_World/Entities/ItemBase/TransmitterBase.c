modded class TransmitterBase
{
	protected PluginZoneBroadcasting		m_pluginZoneBroadcasting;
	protected EffectSound					m_broadcastSound;
	protected float							m_broadcastSoundMaxVolume;
	
	void TransmitterBase()
	{
		m_pluginZoneBroadcasting = PluginZoneBroadcasting.Cast(GetPlugin(PluginZoneBroadcasting));
		if (m_pluginZoneBroadcasting)
			m_pluginZoneBroadcasting.AddTransmitter(this);
		
		m_broadcastSoundMaxVolume = 1.0;
	}
	
	void ~TransmitterBase()
	{
		if ( GetGame() )
		{
			if (m_pluginZoneBroadcasting)
				m_pluginZoneBroadcasting.RemoveTransmitter(this);
		
			StopBroadcastSound();
		}
	}

	override void SetNextFrequency( PlayerBase player = NULL )
	{
		super.SetNextFrequency(player);
		
		if (IsZoneBroadcastFrequency())
		{
			EnableBroadcast ( false );
		}
		else
		{
			StopBroadcastSound();
			EnableBroadcast ( true );
		}
	}
	
	override void OnWorkStart()
	{
		super.OnWorkStart();
		
		if (IsZoneBroadcastFrequency())
		{
			EnableBroadcast ( false );
		}
	}
	
	override void OnWorkStop()
	{
		super.OnWorkStop();
		
		StopBroadcastSound();
	}
	
	bool IsZoneBroadcastFrequency()
	{
		if (m_pluginZoneBroadcasting)
			return m_pluginZoneBroadcasting.IsZoneBroadcastFrequency(GetTunedFrequency());
		
		return false;
	}
	
	void PlayBroadcastSound(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( (!GetGame().IsMultiplayer() || GetGame().IsClient()) && IsZoneBroadcastFrequency() && GetCompEM().IsWorking() )
		{
			PlaySoundSet(m_broadcastSound, soundSet, fadeIn, fadeOut, loop);
			if (m_broadcastSound)
				m_broadcastSound.SetSoundMaxVolume(m_broadcastSoundMaxVolume);
		}
	}
	
	protected void StopBroadcastSound()
	{
		StopSoundSet( m_broadcastSound );
	}	
}