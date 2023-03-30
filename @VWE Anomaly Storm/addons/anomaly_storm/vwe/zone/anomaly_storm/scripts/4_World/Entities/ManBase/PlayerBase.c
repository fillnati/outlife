modded class PlayerBase
{	
	protected PluginEventAnomalyStorm				m_pluginEventAnomalyStorm;
	protected ref AnomalyStormSyncDataClient		m_anomalyStormSyncDataClient;
	protected bool									m_anomalyStormSyncDataClientNeedUpdate;

	override void Init()
	{
		m_pluginEventAnomalyStorm = PluginEventAnomalyStorm.Cast( GetPlugin(PluginEventAnomalyStorm) );
		m_anomalyStormSyncDataClient = new AnomalyStormSyncDataClient();
		m_anomalyStormSyncDataClientNeedUpdate = false;
		super.Init();
	}

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		super.OnRPC(sender, rpc_type, ctx);
		
		if (GetGame().IsClient())
		{
			switch( rpc_type )
			{
				case ERPCsEAS.RPC_EVENT_ANOMALY_STORM_SYNC:
				{
					if (m_pluginEventAnomalyStorm)
					{
						m_pluginEventAnomalyStorm.OnRPC(sender, rpc_type, ctx);
					}
					break;
				}
			}
		}
	}
	
	void AnomalyStormSendDataClient()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() && m_anomalyStormSyncDataClientNeedUpdate )
		{
			ScriptRPC rpc = new ScriptRPC();
			rpc.Write( m_anomalyStormSyncDataClient );
			rpc.Send( this, ERPCsEAS.RPC_EVENT_ANOMALY_STORM_SYNC_DATA_CLIENT, true, null );
			m_anomalyStormSyncDataClientNeedUpdate = false;
		}
	}
	
	bool IsPlayerInSafePosition()
	{
		return m_anomalyStormSyncDataClient.PlayerInSafePosition;
	}
	
	void PlayerInSafePosition(bool v)
	{
		if (m_anomalyStormSyncDataClient.PlayerInSafePosition != v)
		{
			m_anomalyStormSyncDataClientNeedUpdate = true;
			m_anomalyStormSyncDataClient.PlayerInSafePosition = v;
		}
	}
	
	float GetAnomalyStormProtectionLevel()
	{
		return m_anomalyStormSyncDataClient.ProtectionLevel;
	}
	
	void SetAnomalyStormProtectionLevel(float v)
	{
		if (v < 0.0)
			v = 0.0;
		else if (v > 1.0)
			v = 1.0;
		
		if (m_anomalyStormSyncDataClient.ProtectionLevel != v)
		{
			m_anomalyStormSyncDataClientNeedUpdate = true;
			m_anomalyStormSyncDataClient.ProtectionLevel = v;
		}
	}
}