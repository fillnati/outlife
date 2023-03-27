modded class MissionServer {
    ref OldCodeLockConfig oldCLConfig;
    ref CodeLockConfig newCLConfig;
    string configDir
    string permsDir;
    // Just store the config on DayZGame so server/client can call to the same location. 
    // It can be called to from there or checks can be called directly to the config object class. 
    // No need for all this bullshit

    void MissionServer() {
        configDir = CLConst.clModFolder + CLConst.clConfigName;

        if (FileExist(CLConst.oldConfigPath)) {
            TransferOldCodeLockConfig();
        }

        if (!FileExist(configDir)) {
            if (!newCLConfig) {
                newCLConfig = new CodeLockConfig();
            }
            GetDayZGame().SetCodeLockConfig(newCLConfig);
            SaveCodeLockConfig();
        } else {
            LoadCodeLockConfig();
            GetDayZGame().SetCodeLockConfig(newCLConfig);
            SaveCodeLockConfig();
        }
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetCLPermissionManager().LoadPermissions, GetDayZGame().GetCodeLockConfig().GetConfigReloadTime() * 1000, true);
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
        super.InvokeOnConnect(player, identity);

        if (!player) { return; }

        if (GetCLPermissionManager().UserIsAdmin(identity.GetPlainId())) {
            auto params = new Param2<ref array<ref CodeLockAdmin>, string>(GetCLPermissionManager().GetAdmins(), identity.GetPlainId());
            GetCodeLockLogger().WriteLog("admin", identity, vector.Zero, "join");
            GetGame().RPCSingleParam(player, CLRPC.RPC_CLIENT_SYNCHADMINS, params, true, identity);
        }

        auto configParams = new Param1<CodeLockConfig>(GetDayZGame().GetCodeLockConfig());
        GetGame().RPCSingleParam(player, CLRPC.RPC_CLIENT_SETCONFIG, configParams, true, identity);
    }

    private void TransferOldCodeLockConfig() {
        JsonFileLoader<OldCodeLockConfig>.JsonLoadFile(CLConst.oldConfigPath, oldCLConfig);

        string canCutLock;
        string canAttachToTent;

        if (oldCLConfig.m_CanCutLock) {
            canCutLock = "true";
        } else {
            canCutLock = "false";
        }

        if (oldCLConfig.m_CanAttachtoTent) {
            canAttachToTent = "true";
        } else {
            canAttachToTent = "false";
        }

        newCLConfig = new CodeLockConfig(canCutLock, canAttachToTent);
        delete oldCLConfig;
        DeleteFile(CLConst.oldConfigPath);
    }

    private void SaveCodeLockConfig() {
        JsonFileLoader<CodeLockConfig>.JsonSaveFile(configDir, newCLConfig);
    }

    private void LoadCodeLockConfig() {
        JsonFileLoader<CodeLockConfig>.JsonLoadFile(configDir, newCLConfig);
        newCLConfig.Validate();
    }
}