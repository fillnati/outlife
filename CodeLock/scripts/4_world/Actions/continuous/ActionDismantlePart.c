modded class ActionDismantlePart {
    protected override bool DismantleCondition(PlayerBase player, ActionTarget target, ItemBase item, bool camera_check) {
        Fence fence = Fence.Cast(target.GetObject());

        if (fence && GetDayZGame().GetCodeLockConfig().OwnerOnlyDismantle()) {
            CodeLock codelock = CodeLock.Cast(fence.GetCodeLock());

            if (codelock && !codelock.IsOwner(player.GetIdentity().GetId())) {
                return false;
            }
        }
        return super.DismantleCondition(player, target, item, camera_check);
    }
}