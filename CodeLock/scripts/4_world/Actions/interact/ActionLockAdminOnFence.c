class ActionLockAdminOnFence : ActionInteractBase {
    protected string lockState;

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText() {
        return lockState;
    }

    override bool IsInstant() {
        return true;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        Fence fence = Fence.Cast(target.GetObject());
        CodeLock codelock;

        if (fence && !fence.IsOpened()) {
            codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (GetCLPermissionManager().UserIsAdmin(player.GetIdentity().GetPlainId())) {
                        lockState = "Admin Lock";
                        return true;
                    }
                }
            }
        }
        return false;
    }

    override void OnStartClient(ActionData action_data) {
        PlayerBase player = action_data.m_Player;
        PlayerIdentity identity = player.GetIdentity();
        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        CodeLock codelock;

        if (fence) {
            codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (GetCLPermissionManager().UserIsAdmin()) {
                        GetCLUIManager().ShowMenu(CLMENU.ADMIN_CODE_MENU, fence);
                    }
                }
            }
        }
    }
}