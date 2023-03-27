class ToxicSicknessMdfr: ModifierBase
{
	static const int TOXIC_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int TOXIC_AGENT_THRESHOLD_DEACTIVATE = 0;
	float Toxic_Damage = 100;
	float chanceVomit = 0.1;
	float chanceCough = 0.2;
	bool m_IsVomiting;
	bool m_IsCoughing;
	float m_tick;

	override void Init()
	{
		m_TrackActivatedTime 		= false;
		m_ID 										= ToxicModifiers.MDF_TOXICSICKNESS;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 		= DEFAULT_TICK_TIME_ACTIVE;
		m_tick = 0;
	}

	override protected bool ActivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(ToxicAgents.TOXICSICKNESS) > TOXIC_AGENT_THRESHOLD_ACTIVATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override protected void OnActivate(PlayerBase player)
	{
		m_IsVomiting = false;
		m_IsCoughing = false;
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.AttachByType(eNotifiers.NTF_SICK);
		//player.DZ_SetTOXICSick(true);
		player.IncreaseDiseaseCount();
		player.SetIsToxicSick(true);
		Toxic_Damage = GetTZGNRConfig().ToxicBloodLoss;
	}

	override protected void OnDeactivate(PlayerBase player)
	{
		//player.DZ_SetTOXICSick(false);
		player.DecreaseDiseaseCount();
		player.SetIsToxicSick(false);
	}

	override protected bool DeactivateCondition(PlayerBase player)
	{
		if(player.GetSingleAgentCount(ToxicAgents.TOXICSICKNESS) < TOXIC_AGENT_THRESHOLD_DEACTIVATE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override protected void OnTick(PlayerBase player, float deltaT)
	{
		m_tick+=deltaT;
		if(m_tick<60.0)return;
		m_tick = 0;

		if(GetTZGNRConfig())
		{
			Toxic_Damage = GetTZGNRConfig().ToxicBloodLoss;
		}

		float currenthealth = player.GetHealth("GlobalHealth", "Blood");
		player.SetHealth("GlobalHealth", "Blood" ,  currenthealth - Toxic_Damage );
		if(!m_IsCoughing && chanceCough > Math.RandomFloatInclusive(0,1))
		{
			SymptomBase symptom1 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
			m_IsCoughing = true;
		}
		if(!m_IsVomiting && chanceVomit > Math.RandomFloatInclusive(0,1))
		{
			SymptomBase symptom2 = player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
			m_IsVomiting = true;
		}
	}
};
