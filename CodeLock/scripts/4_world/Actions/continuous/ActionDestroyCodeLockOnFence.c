class ActionDestroyCodeLockOnFenceCB : ActionContinuousBaseCB {
    override void CreateActionComponent() {
        // use config if available
        if (GetDayZGame().GetCodeLockConfig()) {
            m_ActionData.m_ActionComponent = new CAContinuousRepeat((GetDayZGame().GetCodeLockConfig().GetGateRaidTime() * 60) / GetDayZGame().GetCodeLockConfig().GetIncrementAmount()); // config value to minutes
        } else {
            // server still verifies action time length
            super.CreateActionComponent();
        }
    }
}

class ActionDestroyCodeLockOnFence : ActionContinuousBase {
    protected float _Health;
    protected float _maxHealth;

    void ActionDestroyCodeLockOnFence() {
        m_CallbackClass = ActionDestroyCodeLockOnFenceCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_DISASSEMBLE;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
        m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_MEDIUM;
        m_FullBody = true;
    }

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined();
        m_ConditionTarget = new CCTNone();
    }

    override string GetText() {
        int healthPercentage = (_Health / _maxHealth) * 100;
        return "Destroy Codelock | HP: " + healthPercentage + "%";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
        Fence fence = Fence.Cast(target.GetObject());
        CodeLock codelock;

        _Health = 0;
        _maxHealth = 0;

        if (fence) {
            Class.CastTo(codelock, fence.GetCodeLock());

            if (codelock && GetDayZGame().GetCodeLockConfig().CanRaidGates()) {
                _Health = codelock.GetSynchronizedHealth();
                _maxHealth = codelock.GetMaxHealth("", "Health");
                return true;
            }
        }
        return false;
    }

    override void OnFinishProgressServer(ActionData action_data) {
        if (!GetDayZGame().GetCodeLockConfig().CanRaidGates()) { return; }

        Fence fence = Fence.Cast(action_data.m_Target.GetObject());
        float raidIncrementAmount = _maxHealth / GetDayZGame().GetCodeLockConfig().GetIncrementAmount();
        int toolDamage = GetDayZGame().GetCodeLockConfig().GetToolDamageonRaid();

        if (fence) {
            CodeLock codelock = fence.GetCodeLock();

            if (codelock) {
                codelock.AddHealth("", "Health", -raidIncrementAmount);

                float _Health = codelock.GetHealth();

                codelock.SetSynchronizedHealth(_Health);

                if (_Health > 0) {
                    GetCodeLockLogger().WriteLog("RAID", action_data.m_Player.GetIdentity(), codelock.GetPosition(), "", false, false, raidIncrementAmount, _Health);
                } else {
                    codelock.NewUnlockServer(action_data.m_Player, fence);

                    if (GetDayZGame().GetCodeLockConfig().DeleteLockonRaid()) {
                        codelock.Delete();
                    }
                    if (toolDamage > 0) {
                        action_data.m_MainItem.DecreaseHealth(toolDamage, false);
                    }
                    GetCodeLockLogger().WriteLog("RAID", action_data.m_Player.GetIdentity(), codelock.GetPosition(), "", false, true);
                }
            }
        }
    }

    override string GetAdminLogMessage(ActionData action_data) {
        return " destroyed CodeLock on " + action_data.m_Target.GetObject().GetDisplayName() + " at " + action_data.m_Player.GetPosition();
    }
}