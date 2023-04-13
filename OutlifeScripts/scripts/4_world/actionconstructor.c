//Made by Pechyvo
modded class PlayerBase extends ManBase
{
	void SetActions(out TInputActionMap InputActionMap)
	{
		super.SetActions(InputActionMap);
		//AWS
		AddAction(ActionDismountNFATACR_B13_RMR, InputActionMap);
	}
};

modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		//AWS
		actions.Insert(ActionDismountNFATACR_B13_RMR);
	}
};