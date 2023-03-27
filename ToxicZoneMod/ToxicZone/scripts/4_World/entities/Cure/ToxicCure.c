class ToxicCure: Inventory_Base
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionInjectToxicCureTarget);
		AddAction(ActionInjectToxicCureSelf);
	}

	override void OnApply(PlayerBase player)
	{
		if( player.GetModifiersManager().IsModifierActive(ToxicModifiers.MDF_TOXICCURE ) )//effectively resets the timer
		{
			player.GetModifiersManager().DeactivateModifier( ToxicModifiers.MDF_TOXICCURE );
		}
		player.GetModifiersManager().ActivateModifier( ToxicModifiers.MDF_TOXICCURE );
	}
};
