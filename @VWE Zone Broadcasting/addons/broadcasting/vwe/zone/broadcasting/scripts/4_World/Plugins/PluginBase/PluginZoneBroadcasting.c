/*
	transmitter frequency
	
	Index	Frequency
	0		87.8
	1		89.5
	2		91.3
	3		91.9
	4		94.6
	5		96.6
	6		99.7
	7		102.5
*/

class PluginZoneBroadcasting extends PluginBase
{
	private float							m_zoneBroadcastFrequency;
	private ref array<ZoneRadioBase>		m_zoneRadios;
	private ref array<TransmitterBase>		m_transmitters;
	private ref array<PASReceiver>			m_pasReceivers;
	
	void PluginZoneBroadcasting()
	{
		Print("[PluginZoneBroadcasting][Client] version: " + GetGame().ConfigGetTextOut("CfgPatches vwe_zone_broadcasting version"));
		m_zoneBroadcastFrequency = 87.8;
		m_zoneRadios = new array<ZoneRadioBase>;
		m_transmitters = new array<TransmitterBase>;
		m_pasReceivers = new array<PASReceiver>;
	}
	
	override void OnInit()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{			
			Print("[PluginZoneBroadcasting][Client] Плагин инициализирован...");
		}
	}
/*	
	override void OnUpdate(float delta_time)
	{
		if ( GetGame().GetMission().IsServer() || GetGame().GetMission().IsMissionGameplay() )
		{
			if (GetGame().IsServer())
			{
				UpdateServer();
			}
		
			if (GetGame().IsClient() || !GetGame().IsMultiplayer())
			{
				UpdateClient();
			}
		}
	}
	
	private void UpdateClient() {}
	private void UpdateServer() {}
*/	
	bool IsZoneBroadcastFrequency(float frequency)
	{
		return frequency == m_zoneBroadcastFrequency;
	}
	
	void AddZoneRadio(ZoneRadioBase radio)
	{
		if (radio && m_zoneRadios.Find(radio) == -1)
			m_zoneRadios.Insert(radio);
	}
	
	void RemoveZoneRadio(ZoneRadioBase radio)
	{
		if (radio)
			m_zoneRadios.RemoveItem(radio);
	}
	
	array<ZoneRadioBase> GetZoneRadios()
	{
		return m_zoneRadios;
	}
	
	void AddTransmitter(TransmitterBase transmitter)
	{
		if (transmitter && m_transmitters.Find(transmitter) == -1)
			m_transmitters.Insert(transmitter);
	}
	
	void RemoveTransmitter(TransmitterBase transmitter)
	{
		if (transmitter)
			m_transmitters.RemoveItem(transmitter);
	}
	
	array<TransmitterBase> GetTransmitters()
	{
		return m_transmitters;
	}
	
	void AddPASReceiver(PASReceiver receiver)
	{
		if (receiver && m_pasReceivers.Find(receiver) == -1)
			m_pasReceivers.Insert(receiver);
	}
	
	void RemovePASReceiver(PASReceiver receiver)
	{
		if (receiver)
			m_pasReceivers.RemoveItem(receiver);
	}
	
	array<PASReceiver> GetPASReceivers()
	{
		return m_pasReceivers;
	}
	
	void Broadcast(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			for (int i = 0; i < m_zoneRadios.Count(); i++)
			{
				ZoneRadioBase radio = ZoneRadioBase.Cast(m_zoneRadios.Get(i));
				if (radio)
					radio.PlayBroadcastSound(soundSet);
			}
			
			for (int j = 0; j < m_transmitters.Count(); j++)
			{
				TransmitterBase transmitter = TransmitterBase.Cast(m_transmitters.Get(j));
				if (transmitter)
					transmitter.PlayBroadcastSound(soundSet);
			}
		}
	}
	
	void BroadcastToPASReceivers(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
		{
			for (int i = 0; i < m_pasReceivers.Count(); i++)
			{
				PASReceiver receiver = PASReceiver.Cast(m_pasReceivers.Get(i));
				
				if (Land_Lamp_City1_amp.Cast(receiver))
					Land_Lamp_City1_amp.Cast(receiver).PlayBroadcastSound(soundSet, fadeIn, fadeOut, loop);
				else if (Land_Power_Pole_Conc1_Amp.Cast(receiver))
					Land_Power_Pole_Conc1_Amp.Cast(receiver).PlayBroadcastSound(soundSet, fadeIn, fadeOut, loop);
				else if (Land_Power_Pole_Conc4_Lamp_Amp.Cast(receiver))
					Land_Power_Pole_Conc4_Lamp_Amp.Cast(receiver).PlayBroadcastSound(soundSet, fadeIn, fadeOut, loop);
				else if (Land_Power_Pole_Wood1_Amp.Cast(receiver))
					Land_Power_Pole_Wood1_Amp.Cast(receiver).PlayBroadcastSound(soundSet, fadeIn, fadeOut, loop);
				else if (Land_Power_Pole_Wood1_Lamp_Amp.Cast(receiver))
					Land_Power_Pole_Wood1_Lamp_Amp.Cast(receiver).PlayBroadcastSound(soundSet, fadeIn, fadeOut, loop);
			}
		}
	}
}