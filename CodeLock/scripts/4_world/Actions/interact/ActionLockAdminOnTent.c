class ActionLockAdminOnTent : ActionInteractBase {
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

    override bool IsUsingProxies() {
        return true;
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        TentBase tent = TentBase.Cast(target.GetParent());
        CodeLock codelock;

        if (tent) {
            if (GetGame().IsServer()) {
                codelock = CodeLock.Cast(tent.GetCodeLock());
            }
            else if (tent.GetTentEntranceAnimationState(target)) {
                codelock = CodeLock.Cast(tent.GetCodeLock());
            }

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
        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());
        CodeLock codelock;

        if (tent) {
            codelock = CodeLock.Cast(tent.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (GetCLPermissionManager().UserIsAdmin()) {
                        GetCLUIManager().ShowMenu(CLMENU.ADMIN_CODE_MENU, tent);
                    }
                }
            }
        }
    }
}