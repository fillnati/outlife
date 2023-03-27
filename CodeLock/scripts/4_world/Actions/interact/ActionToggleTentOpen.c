modded class ActionToggleTentOpen : ActionInteractBase {
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        if (super.ActionCondition(player, target, item)) {
            TentBase tent = TentBase.Cast(target.GetParent());
            
            if (tent) {
                if (tent.GetTentEntranceAnimationState(target) && tent.IsCodeLocked()) { return false; }
            }
            return true;
        }
        return false;
    }
}