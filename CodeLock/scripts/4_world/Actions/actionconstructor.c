modded class ActionConstructor {
    override void RegisterActions(TTypenameArray actions) {
        super.RegisterActions(actions);

        actions.Insert(ActionDestroyCodeLockOnFence);
        actions.Insert(ActionDestroyCodeLockOnTent);
        actions.Insert(ActionInteractLockOnFence);
        actions.Insert(ActionInteractLockOnTent);
        actions.Insert(ActionAttachCodeLockToFence);
        actions.Insert(ActionAttachCodeLockToTent);
        actions.Insert(ActionManageLockOnTent);
        actions.Insert(ActionManageLockOnFence);
        actions.Insert(ActionLockAdminOnFence);
        actions.Insert(ActionLockAdminOnTent);
    }
}