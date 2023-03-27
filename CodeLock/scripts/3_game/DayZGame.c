// store the config values here so that they can be accessed
// "globally" and synced with the client and server

modded class DayZGame {
    protected ref CodeLockConfig codeLockConfig;
    private bool isCodeLockActionRateLimited;
    private bool isCodeLockUIRateLimited;

    ref CodeLockConfig GetCodeLockConfig() {
        return codeLockConfig;
    }

    void SetCodeLockConfig(ref CodeLockConfig config) {
        codeLockConfig = config;
    }

    // --- Client functions
    // --- Rate Limiting

    void SetCLActionRateLimit() {
        if (!isCodeLockActionRateLimited) {
            isCodeLockActionRateLimited = true;
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CLRemoveActionRateLimit, codeLockConfig.GetActionRateLimit() * 1000, false);
        }
    }

    void SetCLUIRateLimit() {
        if (!isCodeLockUIRateLimited) {
            isCodeLockUIRateLimited = true;
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(CLRemoveUIRateLimit, codeLockConfig.GetUIRateLimit() * 1000, false);
        }
    }

    private void CLRemoveActionRateLimit() {
        isCodeLockActionRateLimited = false;
    }

    private void CLRemoveUIRateLimit() {
        isCodeLockUIRateLimited = false;
    }

    bool CLIsActionRateLimited() {
        return isCodeLockActionRateLimited;
    }

    bool CLIsUIRateLimited() {
        return isCodeLockUIRateLimited;
    }
}