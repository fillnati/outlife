modded class Hacksaw
{
    override void SetActions()
	{
		super.SetActions();

        AddAction(ActionDestroyCodeLockOnFence);
        AddAction(ActionDestroyCodeLockOnTent);
    }
}