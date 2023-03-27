modded class ActionPackTent : ActionInteractBase {
    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        TentBase tent = TentBase.Cast(target.GetParent());

        if (super.ActionCondition(player, target, item)) {
            if (tent) {
                if (tent.IsCodeLocked()) { return false; }
            }
            return true;
        }
        return false;
    }

    override void OnExecuteServer(ActionData action_data) {
        Object targetParent = action_data.m_Target.GetParent();
        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());

        if (tent) {
            if (tent.IsCodeLocked()) { return; }
        }

        super.OnExecuteServer(action_data);
    }
};