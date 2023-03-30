class AnomalyStormLogic : Managed
{
	protected PluginEventAnomalyStorm		m_plugin;
	protected AnomalyStormParams			m_stormParams;
	
	void AnomalyStormLogic()
	{
		m_plugin = PluginEventAnomalyStorm.Cast( GetPlugin(PluginEventAnomalyStorm) );
		m_stormParams = m_plugin.GetParams();
	}
	
	void ~AnomalyStormLogic()
	{
		
	}
	
	bool IsStartOvercast() { return false; }
	void SetStartOvercast() {}
	bool IsBroadcastMessageWarning() { return false; }
	
	void StormWarning() {}
	void BeforeStormPhaseStart() {}
	void OnStormPhaseStart() {}
	void AfterStormPhaseStart() {}
	void BeforeStormPhaseRun() {}
	void OnStormPhaseRun() {}
	void AfterStormPhaseRun() {}
	void BeforeStormPhaseEnd() {}
	void OnStormPhaseEnd() {}
	void AfterStormPhaseEnd() {}
	void OnUpdate() {}
	void UpdatePlayerServer(float deltaTime, PlayerBase player) {}
	
	float GetDamageFactor()
	{
		switch( m_plugin.GetStormPhase() )
		{
			case AnomalyStormPhase.BeforeStart:
			{
				return 0;
			}
			case AnomalyStormPhase.Start:
			{
				float phaseValue = m_plugin.GetStormPhaseValue();
				float damageFactor = m_stormParams.GetDamageFactor();
				float val = Clamp(phaseValue - damageFactor) / (1 - damageFactor);
				return val;
			}
			case AnomalyStormPhase.AfterStart:
			{
				return 1;
			}
			case AnomalyStormPhase.BeforeRun:
			{
				return 1;
			}
			case AnomalyStormPhase.Run:
			{
				return 1;
			}
			case AnomalyStormPhase.AfterRun:
			{
				return 1;
			}
			case AnomalyStormPhase.BeforeEnd:
			{
				return 1;
			}
			case AnomalyStormPhase.End:
			{
				return 1 - m_plugin.GetStormPhaseValue();
			}
			case AnomalyStormPhase.AfterEnd:
			{
				return 0;
			}
		}
		
		return 0;
	}
	
	float Clamp(float v, float min = 0, float max = 1)
	{
		if (v < min)
			return min;
		else if (v > max)
			return max;
		return v;
	}
	
	void PrintChat(string t)
	{
		GetGame().GetMission().OnEvent(ChatMessageEventTypeID, new ChatMessageEventParams( 0, "", t, "" ) );
	}
};
