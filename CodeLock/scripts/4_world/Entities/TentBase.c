modded class TentBase {
    bool GetDoorAnimState() {
        CodeLock codelock = CodeLock.Cast(GetCodeLock());

        if (codelock && GetAnimationPhase("EntranceO"))
            return false;

        return true;
    }

    override bool CanReceiveItemIntoCargo(EntityAI item) {
        if (this.IsInherited(LargeTent) || this.IsInherited(MediumTent) || this.IsInherited(CarTent))
            return GetDoorAnimState();
        else
            return super.CanReceiveItemIntoCargo(item);
    }

    override bool CanReleaseCargo(EntityAI cargo) {
        if (this.IsInherited(LargeTent) || this.IsInherited(MediumTent) || this.IsInherited(CarTent))
            return GetDoorAnimState();
        else
            return super.CanReleaseCargo(cargo);
    }

    override bool CanDisplayAttachmentCategory(string category_name) {
        if (category_name == "CodeLock") {
            return GetDayZGame().GetCodeLockConfig().CanAttachToTents();
        }

        return super.CanDisplayAttachmentCategory(category_name);
    }

    override bool CanReceiveAttachment(EntityAI attachment, int slotId) {
        if (CodeLock.Cast(attachment))
            return GetDayZGame().GetCodeLockConfig().CanAttachToTents();

        return super.CanReceiveAttachment(attachment, slotId);
    }

    bool GetTentEntranceAnimationState(ActionTarget target) {
        Object targetObject = target.GetObject();
        array<string> selections = new array<string>();
        targetObject.GetActionComponentNameList(target.GetComponentIndex(), selections);

        bool OpenState = GetAnimationPhase("EntranceO");
        bool CloseState = GetAnimationPhase("EntranceC");

        foreach (string s : selections) {
            if (s.IndexOfFrom(0, "window") && CanToggleAnimations(s)) {
                if (!CloseState && !OpenState) { return true; }
                if (OpenState) { return true; }
            }
        }
        return false;
    }

    override void SetActions() {
        super.SetActions();
        AddAction(ActionInteractLockOnTent);
        AddAction(ActionManageLockOnTent);
        AddAction(ActionLockAdminOnTent);
    }
}