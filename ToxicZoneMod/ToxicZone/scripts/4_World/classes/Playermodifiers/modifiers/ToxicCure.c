class ToxicCureMdfr: ModifierBase
{
	float 			m_LastWaterLevel;
	ref HumanMovementState		m_MovementState	= new HumanMovementState();
	float m_RegenTime;
	float m_TickMin;

	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= ToxicModifiers.MDF_TOXICCURE;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= DEFAULT_TICK_TIME_ACTIVE;
		m_RegenTime = 5;
		m_TickMin = 0;
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}

	override string GetDebugText()
	{
		return (m_RegenTime - GetAttachedTime()).ToString();
	}

	override void OnActivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		player.m_ModifiersManager.DeactivateModifier(ToxicModifiers.MDF_TOXICSICKNESS);
		player.GiveShock(-100);
		player.AddHealth( "", "", -40);
		player.RemoveAgent(ToxicAgents.TOXICSICKNESS);
		player.IsToxicSick=false;
	}

	override void OnDeactivate(PlayerBase player)
	{
		if( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();

		if( attached_time >= m_RegenTime )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnTick(PlayerBase player, float deltaT)
	{

	}
};
