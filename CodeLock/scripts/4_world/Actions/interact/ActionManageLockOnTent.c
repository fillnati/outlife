class ActionManageLockOnTent : ActionInteractBase {
    protected string lockState;

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINone;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText() {
        return lockState;
    }

    override typename GetInputType() {
        return ContinuousInteractActionInput;
    }

    override bool HasProgress() {
        return false;
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
                bool isOwner = codelock.IsOwner(player.GetIdentity().GetId());
                
                if (codelock.GetLockState()) {
                    if (isOwner) {
                        lockState = "Manage Lock";
                        return true;
                    } else if (codelock.HasNoOwner()) {
                        lockState = "Claim Ownership";
                        return true;
                    }
                }
            }
        }
        return false;
    }

    override bool CanContinue(ActionData action_data) {
        return true;
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
                    if (codelock.IsOwner(identity.GetId())) {
                        GetCLUIManager().ShowMenu(CLMENU.ENTER_CODE_MENU, tent);
                    } else if (codelock.HasNoOwner()) {
                        GetCLUIManager().ShowMenu(CLMENU.CLAIM_CODE_MENU, tent);
                    }
                }
            }
        }
    }

    override void CreateAndSetupActionCallback(ActionData action_data) {
        super.CreateAndSetupActionCallback(action_data);
    }
}