class CodeLockPermissionManager : PluginBase {
    private ref array<ref CodeLockAdmin> arrayAdmins;
    private string permsDir;
    private string clientPlainId;

    void CodeLockPermissionManager() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            return;
        }

        permsDir = CLConst.clModFolder + CLConst.clPermissionName;

        if (!arrayAdmins) {
            arrayAdmins = new array<ref CodeLockAdmin>();
        }

        if (!FileExist(permsDir)) {
            CreatePermissionFile();
        }
        LoadPermissions();
    }

    private void CreatePermissionFile() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        CodeLockAdmin exPlayer = new CodeLockAdmin();
        arrayAdmins.Insert(exPlayer);
        arrayAdmins.Insert(exPlayer);

        JsonFileLoader<ref array<ref CodeLockAdmin>>.JsonSaveFile(permsDir, arrayAdmins);
    }

    void LoadPermissions() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        JsonFileLoader<ref array<ref CodeLockAdmin>>.JsonLoadFile(permsDir, arrayAdmins);

        if (arrayAdmins.Count() < 1) {
            CreatePermissionFile();
            return;
        }
        JsonFileLoader<ref array<ref CodeLockAdmin>>.JsonSaveFile(permsDir, arrayAdmins);

    }

    void SetClientAdmin(ref array<ref CodeLockAdmin> admins, string plainId) {
        if (GetGame().IsServer() || !GetGame().IsClient()) { return; }

        arrayAdmins = admins;
        clientPlainId = plainId;
    }

    ref array<ref CodeLockAdmin> GetAdmins() {
        return arrayAdmins;
    }

    bool CanOpenLocks(string playerId = "") {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            playerId = clientPlainId;
        }
        if (playerId == string.Empty) { return false; }

        CodeLockPerms localPerms;

        for (int i = 0; i < arrayAdmins.Count(); i++) {
            CodeLockAdmin playerPerms = arrayAdmins[i];

            if (playerPerms.IsPlayer(playerId)) {
                localPerms = playerPerms.GetPlayerPerms();
                break;
            }
        }
        if (localPerms) {
            return localPerms.CanOpenLocks();
        }
        return false;
    }

    bool CanChangePasscodes(string playerId = "") {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            playerId = clientPlainId;
        }
        if (playerId == string.Empty) { return false; }

        CodeLockPerms localPerms;

        for (int i = 0; i < arrayAdmins.Count(); i++) {
            CodeLockAdmin playerPerms = arrayAdmins[i];

            if (playerPerms.IsPlayer(playerId)) {
                localPerms = playerPerms.GetPlayerPerms();
                break;
            }
        }
        if (localPerms) {
            return localPerms.CanChangePasscodes();
        }
        return false;
    }

    bool CanRemoveLocks(string playerId = "") {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            playerId = clientPlainId;
        }
        if (playerId == string.Empty) { return false; }

        CodeLockPerms localPerms;

        for (int i = 0; i < arrayAdmins.Count(); i++) {
            CodeLockAdmin playerPerms = arrayAdmins[i];

            if (playerPerms.IsPlayer(playerId)) {
                localPerms = playerPerms.GetPlayerPerms();
                break;
            }
        }
        if (localPerms) {
            return localPerms.CanRemoveLocks();
        }
        return false;
    }

    bool UserIsAdmin(string playerId = "") {;
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            playerId = clientPlainId;
        }
        if (playerId == string.Empty) { return false; }

        CodeLockPerms localPerms;

        for (int i = 0; i < arrayAdmins.Count(); i++) {
            CodeLockAdmin playerPerms = arrayAdmins[i];

            if (playerPerms.IsPlayer(playerId)) {
                localPerms = playerPerms.GetPlayerPerms();
                break;
            }
        }
        if (localPerms) {
            if (localPerms.CanRemoveLocks() || localPerms.CanChangePasscodes() || localPerms.CanOpenLocks()) {
                return true;
            }
        }
        return false;
    }

    bool UserIsSuperAdmin(string playerId) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return false; }

        CodeLockPerms localPerms;

        for (int i = 0; i < arrayAdmins.Count(); i++) {
            CodeLockAdmin playerPerms = arrayAdmins[i];

            if (playerPerms.IsPlayer(playerId)) {
                localPerms = playerPerms.GetPlayerPerms();
                break;
            }
        }
        if (localPerms) {
            if (localPerms.CanRemoveLocks() && localPerms.CanChangePasscodes() && localPerms.CanOpenLocks()) {
                return true;
            }
        }
        return false;
    }
}
CodeLockPermissionManager GetCLPermissionManager() {
    return CodeLockPermissionManager.Cast(GetPlugin(CodeLockPermissionManager));
}