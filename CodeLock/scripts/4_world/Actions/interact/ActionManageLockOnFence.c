class ActionManageLockOnFence : ActionInteractBase {
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

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        Fence fence = Fence.Cast(target.GetObject());
        CodeLock codelock;

        if (fence && !fence.IsOpened()) {
            if (!GetDayZGame().GetCodeLockConfig().CanOpenAnywhere()) {
                string selection = fence.GetActionComponentName(target.GetComponentIndex());

                if (selection != "wall_interact") {
                    return false;
                }
            }
            codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock) {
                bool isOwner = codelock.IsOwner(player.GetIdentity().GetId());
                bool isGuest = codelock.IsGuest(player.GetIdentity().GetId());
                
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
        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        CodeLock codelock;

        if (fence) {
            codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (codelock.IsOwner(identity.GetId())) {
                        GetCLUIManager().ShowMenu(CLMENU.ENTER_CODE_MENU, fence);
                    } else if (codelock.HasNoOwner()) {
                        GetCLUIManager().ShowMenu(CLMENU.CLAIM_CODE_MENU, fence);
                    }
                }
            }
        }
    }

    override void CreateAndSetupActionCallback(ActionData action_data) {
        super.CreateAndSetupActionCallback(action_data);
    }
}