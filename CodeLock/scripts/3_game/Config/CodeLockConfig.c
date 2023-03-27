class OldCodeLockConfig {
    bool m_CanCutLock;
    bool m_CanAttachtoTent;
}

class CodeLockConfig {
    private int ActionRateLimit;
    private int UIRateLimit;
    private int PermissionReloadTime;
    private int RaidIncrements;
    private float GateRaidTime;
    private float TentRaidTime;
    private string CanAttachToGates;
    private string CanAttachToTents;
    private string CanRaidGates;
    private string CanRaidTents;
    private string DeleteLockonRaid;
    private int ToolDamageonRaid;
    private string OwnerOnlyDismantle;
    private string CanOpenAnywhere;
    private string CanCloseAnywhere;

    // Assign defaults
    void CodeLockConfig(string canCutLock = "true", string canAttachToTents = "false") {
        ActionRateLimit = 5;
        UIRateLimit = 1;
        PermissionReloadTime = 60;
        RaidIncrements = 5;
        GateRaidTime = 15;
        TentRaidTime = 15;
        ToolDamageonRaid = 100;
        CanAttachToGates = "true";
        CanAttachToTents = canAttachToTents;
        CanRaidGates = canCutLock;
        CanRaidTents = canCutLock;
        DeleteLockonRaid = "false";
        OwnerOnlyDismantle = "true";
        CanOpenAnywhere = "true";
        CanCloseAnywhere = "true";
    }

    int GetActionRateLimit() {
        return ActionRateLimit;
    }

    int GetUIRateLimit() {
        return UIRateLimit;
    }

    float GetConfigReloadTime() {
        return PermissionReloadTime;
    }

    float GetGateRaidTime() {
        return GateRaidTime;
    }

    float GetTentRaidTime() {
        return TentRaidTime;
    }

    bool CanAttachToGates() {
        string loweredString = CanAttachToGates;
        loweredString.ToLower();

        return loweredString == "true";
    }

    bool CanAttachToTents() {
        string loweredString = CanAttachToTents;
        loweredString.ToLower();

        return loweredString == "true";
    }

    bool CanRaidGates() {
        string loweredString = CanRaidGates;
        loweredString.ToLower();

        return loweredString == "true";
    }

    bool CanRaidTents() {
        string loweredString = CanRaidTents;
        loweredString.ToLower();

        return loweredString == "true";
    }

    bool DeleteLockonRaid() {
        string loweredString = DeleteLockonRaid;
        loweredString.ToLower();

        return loweredString == "true";
    }
    
    bool OwnerOnlyDismantle() {
        string loweredString = OwnerOnlyDismantle;
        loweredString.ToLower();

        return loweredString == "true";
    }
    
    bool CanOpenAnywhere() {
        string loweredString = CanOpenAnywhere;
        loweredString.ToLower();

        return loweredString == "true";
    }
    
    bool CanCloseAnywhere() {
        string loweredString = CanCloseAnywhere;
        loweredString.ToLower();

        return loweredString == "true";
    }

    int GetToolDamageonRaid() {
        return ToolDamageonRaid;
    }

    int GetIncrementAmount() {
        return RaidIncrements;
    }

    void Validate() {
        if (ActionRateLimit < 1) {
            ActionRateLimit = 5;
        }
        if (UIRateLimit < 1) {
            UIRateLimit = 1;
        }
        if (PermissionReloadTime < 1) {
            PermissionReloadTime = 60;
        }
        if (GateRaidTime < 1) {
            GateRaidTime = 15;
        }
        if (TentRaidTime < 1) {
            TentRaidTime = 15;
        }
        if (RaidIncrements < 1) {
            RaidIncrements = 3;
        }
        if (ToolDamageonRaid < 0) {
            ToolDamageonRaid = 100;
        }
        if (OwnerOnlyDismantle == string.Empty) {
            OwnerOnlyDismantle = "true";
        }
        if (CanOpenAnywhere == string.Empty) {
            CanOpenAnywhere = "true";
        }
        if (CanCloseAnywhere == string.Empty) {
            CanCloseAnywhere = "true";
        }
    }
}