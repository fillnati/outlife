class PluginEventAnomalyStorm extends PluginBase
{
	private int								m_timeStamp;
	private int								m_stormType;
	private int								m_stormState;
	private int								m_stormPhase;
	private float							m_stormPhaseValue;
	private ref AnomalyStormParams			m_stormParams;
	private ref AnomalyStormLogic			m_logicClient;
	private bool							m_clientInitialized;
	private bool							m_isShowNotification;
	private bool							m_isPlaySoundAlarm;

	private PluginZoneBroadcasting			m_pluginZoneBroadcasting;
	
	void PluginEventAnomalyStorm()
	{
		Print("[PluginEventAnomalyStorm][Client] version: " + GetGame().ConfigGetTextOut("CfgPatches VWE_Zone_Anomaly_Storm version"));
		
		m_timeStamp = GetGame().GetTime();
		m_stormType = AnomalyStormType.Storm;
		m_stormState = AnomalyStormState.Idle;
		m_stormPhase = AnomalyStormPhase.None;
		m_stormPhaseValue = 0;
		m_stormParams = new AnomalyStormParams();
		m_isShowNotification = m_stormParams.IsShowNotification();
		m_isPlaySoundAlarm = m_stormParams.IsPlaySoundAlarm();
		m_clientInitialized = false;
	}
	
	override void OnInit()
	{
		if ( GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{
			typename logicClientType = m_stormParams.GetLogicClientName().ToType();
			if (logicClientType)
			{
				m_logicClient = AnomalyStormLogic.Cast( logicClientType.Spawn() );
				if (m_logicClient)
				{
					m_clientInitialized = true;
					Print("[PluginEventAnomalyStorm::OnInit][Client] Плагин инициализирован...");
				}
			}
			
			m_pluginZoneBroadcasting = PluginZoneBroadcasting.Cast(GetPlugin(PluginZoneBroadcasting));
		}
	}
	
	override void OnDestroy() {}
	
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
	
	private void UpdateClient()
	{
		if (m_clientInitialized && (m_stormState == AnomalyStormState.Active))
			m_logicClient.OnUpdate();
	}
	
	private void UpdateServer() {}
	
	void OnRPC(PlayerIdentity sender, int rpcType, ParamsReadContext ctx)
	{
		switch( rpcType )
		{
			case ERPCsEAS.RPC_EVENT_ANOMALY_STORM_SYNC:
			{
				int v1, v2, v3;
				float v4, v7;
				bool b1, b2, b3, b4, b5, b6, b7, v5, v6;

				b1 = ctx.Read(v1);
				b2 = ctx.Read(v2);
				b3 = ctx.Read(v3);
				b4 = ctx.Read(v4);
				b5 = ctx.Read(v5);
				b6 = ctx.Read(v6);
				b7 = ctx.Read(v7);

				if (b1 && b2 && b3 && b4 && b5 && b6 && b7)
				{
					m_stormType = v1;
					m_stormState = v2;
					m_stormPhase = v3;
					m_stormPhaseValue = v4;
					m_isShowNotification = v5;
					m_isPlaySoundAlarm = v6;
					GetParams().SetDamageFactor(v7);
					UpdateStormClient();
				}
				else
				{
					Print( string.Format("[PluginEventAnomalyStorm::OnRPC::RPC_EVENT_ANOMALY_STORM_SYNC][Client][Error] Данные синхронизации не корректно десериализованы, b1:%1 b2:%2 b3:%3 b4:%4 b5:%5 b6:%6 b7:%7", b1, b2, b3, b4, b5, b6, b7) );
				}
				break;
			}
		}
	}
	
	private void UpdateStormClient()
	{
		if (!m_clientInitialized || !GetGame().GetPlayer()) return;
		
		switch( m_stormState )
		{
			case AnomalyStormState.Warning:
			{
				m_logicClient.StormWarning();
				break;
			}
			case AnomalyStormState.Active:
			{
				switch( m_stormPhase )
				{
					case AnomalyStormPhase.BeforeStart:
					{
						m_logicClient.BeforeStormPhaseStart();
						break;
					}
					case AnomalyStormPhase.Start:
					{
						m_logicClient.OnStormPhaseStart();
						break;
					}
					case AnomalyStormPhase.AfterStart:
					{
						m_logicClient.AfterStormPhaseStart();
						break;
					}
					case AnomalyStormPhase.BeforeRun:
					{
						m_logicClient.BeforeStormPhaseRun();
						break;
					}
					case AnomalyStormPhase.Run:
					{
						m_logicClient.OnStormPhaseRun();
						break;
					}
					case AnomalyStormPhase.AfterRun:
					{
						m_logicClient.AfterStormPhaseRun();
						break;
					}
					case AnomalyStormPhase.BeforeEnd:
					{
						m_logicClient.BeforeStormPhaseEnd();
						break;
					}
					case AnomalyStormPhase.End:
					{
						m_logicClient.OnStormPhaseEnd();
						break;
					}
					case AnomalyStormPhase.AfterEnd:
					{
						m_logicClient.AfterStormPhaseEnd();
						break;
					}
				}
				
				break;
			}
		}
	}

	void BroadcastToPASReceivers(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( (!GetGame().IsMultiplayer() || GetGame().IsClient()) && m_pluginZoneBroadcasting)
		{
			m_pluginZoneBroadcasting.BroadcastToPASReceivers(soundSet, fadeIn, fadeOut, loop);
		}
	}
	
	void BroadcastToZoneRadios(string soundSet, float fadeIn = 0.0, float fadeOut = 0.0, bool loop = false)
	{
		if ( (!GetGame().IsMultiplayer() || GetGame().IsClient()) && m_pluginZoneBroadcasting )
		{
			m_pluginZoneBroadcasting.Broadcast(soundSet, fadeIn, fadeOut, loop);
		}
	}
	
	AnomalyStormParams GetParams() { return m_stormParams; }	
	int GetStormType() { return m_stormType; }
	int GetStormState() { return m_stormState; }
	int GetStormPhase() { return m_stormPhase; }
	float GetStormPhaseValue() { return m_stormPhaseValue; }
	bool IsShowNotification() { return m_isShowNotification; }
	bool IsPlaySoundAlarm() { return m_isPlaySoundAlarm; }
	
	float GetDamageFactor()
	{
		return m_logicClient.GetDamageFactor();
	}
};
