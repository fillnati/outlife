modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		actions.Insert(ActionInjectToxicCureSelf);
		actions.Insert(ActionInjectToxicCureTarget);
		super.RegisterActions(actions);
	}
};
