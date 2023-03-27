class ActionAttachCodeLockToTent : ActionSingleUseBase {
    override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText() {
        return "Attach Codelock";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        TentBase tent = TentBase.Cast(target.GetParent());

        if (tent && tent.GetState()) {
            if (!GetDayZGame().GetCodeLockConfig().CanAttachToTents()) {
                return false;
            }
            if (tent.IsInherited(LargeTent) || tent.IsInherited(MediumTent) || tent.IsInherited(CarTent)) {
                if (!tent.IsCodeLocked())
                    return true;
            }
        }
        return false;
    }

    override void OnExecuteClient(ActionData action_data) {
        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());
        PlayerBase player = action_data.m_Player;

		ClearInventoryReservationEx(action_data);

        if (tent) {
            int slotID = InventorySlots.GetSlotIdFromString(CLConst.clAttachment);

            action_data.m_Player.PredictiveTakeEntityToTargetAttachmentEx(tent, action_data.m_MainItem, slotID);
            GetCLUIManager().ShowMenu(CLMENU.SET_CODE_MENU, tent);
        }
    }

    override void OnExecuteServer(ActionData action_data) {
        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());
        PlayerIdentity playerId = action_data.m_Player.GetIdentity();

        if (tent) {
            GetCodeLockLogger().WriteLog("attach", playerId, tent.GetPosition());
        }
    }
}