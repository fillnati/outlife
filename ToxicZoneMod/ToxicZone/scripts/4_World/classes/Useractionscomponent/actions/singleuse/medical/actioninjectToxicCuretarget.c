class ActionInjectToxicCureTarget: ActionInjectTarget
{
	void ActionInjectToxicCureTarget()
	{
		//m_Animation = "INJECTEPINENT";
		//m_MessageStart = "Player started injecting you RadCure.";
		//m_MessageSuccess = "Player finished injecting you RadCure.";
	}

	//override int GetType()
	//{
	//	return AT_INJECT_RADCURE_T;
	//}

	override void ApplyModifiers( ActionData action_data )
	{
		action_data.m_MainItem.OnApply( PlayerBase.Cast(action_data.m_Target.GetObject()));
	}
};
