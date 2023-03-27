// this whole class is a complete rewrite of the original actions
// for CodeLock, this rewrite is much cleaner and easier to read

class ActionDestroyCodeLockOnTentCB : ActionContinuousBaseCB {
    override void CreateActionComponent() {
        // use config if available
        if (GetDayZGame().GetCodeLockConfig()) {
            m_ActionData.m_ActionComponent = new CAContinuousRepeat((GetDayZGame().GetCodeLockConfig().GetTentRaidTime() * 60) / GetDayZGame().GetCodeLockConfig().GetIncrementAmount()); // config value to minutes
        } else {
            // server still verifies action time length
            super.CreateActionComponent();
        }
    }
}

class ActionDestroyCodeLockOnTent : ActionContinuousBase {
    protected float _Health;
    protected float _maxHealth;

    void ActionDestroyCodeLockOnTent() {
        m_CallbackClass = ActionDestroyCodeLockOnTentCB;
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
        TentBase tent = TentBase.Cast(target.GetParent());
        CodeLock codelock;

        _Health = 0;
        _maxHealth = 0;

        if (tent) {
            if (GetGame().IsServer()) {
                codelock = CodeLock.Cast(tent.GetCodeLock());
            } else if (tent.GetTentEntranceAnimationState(target)) {
                codelock = CodeLock.Cast(tent.GetCodeLock());
            }
            if (codelock && GetDayZGame().GetCodeLockConfig().CanRaidTents()) {
                _Health = codelock.GetSynchronizedHealth();
                _maxHealth = codelock.GetMaxHealth("", "Health");
                return true;
            }
        }
        return false;
    }

    override void OnFinishProgressServer(ActionData action_data) {
        if (!GetDayZGame().GetCodeLockConfig().CanRaidTents()) {return;}

        TentBase tent = TentBase.Cast(action_data.m_Target.GetParent());
        float raidIncrementAmount = _maxHealth / GetDayZGame().GetCodeLockConfig().GetIncrementAmount();
        int toolDamage = GetDayZGame().GetCodeLockConfig().GetToolDamageonRaid();

        if (tent) {
            CodeLock codelock = tent.GetCodeLock();

            if (codelock) {
                codelock.AddHealth("", "Health", -raidIncrementAmount);

                float _Health = codelock.GetHealth();

                codelock.SetSynchronizedHealth(_Health);

                if (_Health > 0) {
                    GetCodeLockLogger().WriteLog("RAID", action_data.m_Player.GetIdentity(), codelock.GetPosition(), "", false, false, raidIncrementAmount, _Health);
                } else {
                    codelock.NewUnlockServer(action_data.m_Player, tent);

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
        return " destroyed CodeLock on " + action_data.m_Target.GetParent().GetDisplayName() + " at " + action_data.m_Player.GetPosition();
    }
}