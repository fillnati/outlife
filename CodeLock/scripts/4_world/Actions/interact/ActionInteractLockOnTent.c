class ActionInteractLockOnTent : ActionInteractBase {
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
        EntityAI targetObject = EntityAI.Cast(action_data.m_Target.GetParent());
        TentBase tent = TentBase.Cast(targetObject);
        CodeLock codelock;
        
        if (tent) {
            codelock = CodeLock.Cast(tent.GetCodeLock());

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
        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());
        CodeLock codelock;

        if (tent) {
            codelock = CodeLock.Cast(tent.GetCodeLock());

            if (codelock) {
                if (codelock.GetLockState()) {
                    if (codelock.IsOwner(identity.GetId()) || codelock.IsGuest(identity.GetId())) {
                        GetCodeLockLogger().WriteLog("acceSS", action_data.m_Player.GetIdentity(), codelock.GetPosition());
                        tent.ToggleAnimation("entrancec");
                    }
                }
            }
        }
    }
}