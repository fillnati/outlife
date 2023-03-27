class ActionInjectToxicCureSelf: ActionInjectSelf
{
	//override int GetType()
	//{
	//	return AT_INJECT_RADCURE_S;
	//}

	override void ApplyModifiers( ActionData action_data )
	{
			action_data.m_MainItem.OnApply(action_data.m_Player);
	}
};
