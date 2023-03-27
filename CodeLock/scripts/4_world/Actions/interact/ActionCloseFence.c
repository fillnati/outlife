modded class ActionCloseFence {
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        Fence fence = Fence.Cast(target.GetObject());
        bool superActionCondition = super.ActionCondition(player, target, item);

        if (GetDayZGame().GetCodeLockConfig().CanCloseAnywhere()) {
            if (!superActionCondition) {
                if (fence && fence.CanCloseFence()) {
                    return true;
                }
            }
        }
        return superActionCondition;
    }
}