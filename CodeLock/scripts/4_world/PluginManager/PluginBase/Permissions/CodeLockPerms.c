class CodeLockPerms {
    string CanOpenLocks;
    string CanChangePasscodes;
    string CanRemoveLocks;

    void CodeLockPerms() {
        CanOpenLocks = "false";
        CanChangePasscodes = "false";
        CanRemoveLocks = "false";
    }

    bool CanOpenLocks() {
        CanOpenLocks.ToLower();
        if (CanOpenLocks == "true") {
            return true;
        }
        return false;
    }

    bool CanChangePasscodes() {
        CanChangePasscodes.ToLower();
        if (CanChangePasscodes == "true") {
            return true;
        }
        return false;
    }

    bool CanRemoveLocks() {
        CanRemoveLocks.ToLower();
        if (CanRemoveLocks == "true") {
            return true;
        }
        return false;
    }
}