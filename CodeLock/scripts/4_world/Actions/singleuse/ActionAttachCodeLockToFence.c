class ActionAttachCodeLockToFence : ActionSingleUseBase {
    override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined;
        m_ConditionTarget = new CCTNone;
    }

    override string GetText() {
        return "Attach Codelock";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        Fence fence = Fence.Cast(target.GetObject());

        if (fence) {
            if (!fence.HasFullyConstructedGate()) {
                return false;
            }
            if (!GetDayZGame().GetCodeLockConfig().CanAttachToGates()) {
                return false;
            }
            if (!fence.IsCodeLocked()) {
                return true;
            }
        }
        return false; 
    }

    override void OnExecuteClient(ActionData action_data) {
        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        PlayerBase player = action_data.m_Player;

		ClearInventoryReservationEx(action_data);

        if (fence) {
            int slotID = InventorySlots.GetSlotIdFromString(CLConst.clAttachment);

            action_data.m_Player.PredictiveTakeEntityToTargetAttachmentEx(fence, action_data.m_MainItem, slotID);
            GetCLUIManager().ShowMenu(CLMENU.SET_CODE_MENU, fence);
        }
    }

    override void OnExecuteServer(ActionData action_data) {
        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        PlayerIdentity playerId = action_data.m_Player.GetIdentity();

        if (fence) {
            GetCodeLockLogger().WriteLog("attach", playerId, fence.GetPosition());
        }
    }
}