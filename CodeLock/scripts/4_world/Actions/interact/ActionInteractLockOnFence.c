class ActionInteractLockOnFence : ActionInteractBase {
    protected string lockState;
    protected Fence currentTarget;

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
                    if (isOwner || isGuest) {
                        lockState = "Open Locked Door";
                    } else if (!codelock.HasNoOwner()) {
                        lockState = "Enter Passcode";
                    } else {
                        return false;
                    }
                } else {
                    lockState = "Set Passcode";
                }
                return true;
            }
        }
        return false;
    }

    override void OnStartClient(ActionData action_data) {
        PlayerBase player = action_data.m_Player;
        PlayerIdentity identity = player.GetIdentity();
        EntityAI targetObject = EntityAI.Cast(action_data.m_Target.GetObject());
        Fence fence = Fence.Cast(targetObject);
        CodeLock codelock;

        if (fence) {
            codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (!codelock.IsOwner(identity.GetId()) && !codelock.IsGuest(identity.GetId())) {
                        GetCLUIManager().ShowMenu(CLMENU.GUEST_CODE_MENU, ItemBase.Cast(targetObject));
                    }
                } else {
                    GetCLUIManager().ShowMenu(CLMENU.SET_CODE_MENU, ItemBase.Cast(targetObject));
                }
            }
        }
    }

    override void OnStartServer(ActionData action_data) {
        PlayerBase player = action_data.m_Player;
        PlayerIdentity identity = player.GetIdentity();
        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        CodeLock codelock;

        if (fence) {
            codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (codelock.IsOwner(identity.GetId()) || codelock.IsGuest(identity.GetId())) {
                        GetCodeLockLogger().WriteLog("acceSS", action_data.m_Player.GetIdentity(), codelock.GetPosition());
                        fence.OpenFence();
                    }
                }
            }
        }
    }
}