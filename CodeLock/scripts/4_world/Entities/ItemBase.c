modded class ItemBase {
    bool CanSplitOrCombine() {
        TentBase tent = TentBase.Cast(GetHierarchyParent());

        if (tent && tent.GetCodeLock()) {
            if (!tent.GetDoorAnimState()) {
                return false;
            }
        }
        return true;
    }

    override void CombineItemsClient(EntityAI entity2, bool use_stack_max = true) {
        if (CanSplitOrCombine())
            super.CombineItemsClient(entity2, use_stack_max);
    }

    override void OnRightClick() {
        if (CanSplitOrCombine())
            super.OnRightClick();
    }

    bool IsCodeLocked() {
        if (GetCodeLock()) return true;
        return false;
    }

    CodeLock GetCodeLock() {
        return CodeLock.Cast(FindAttachmentBySlotName("Att_CombinationLock"));
    }
}