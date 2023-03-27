class CodeLockServerRPC : PluginBase {
    PlayerBase player;

    void CodeLockServerRPC() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(ServerRPCHandler);
    }

    void ~CodeLockServerRPC() {
        GetDayZGame().Event_OnRPC.Remove(ServerRPCHandler);
    }

    void ServerRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) {
            delete this;
            return;
        }
        if (!sender) { return; }

        CodeLock codelock;
        ItemBase targetObject;
        string playerId;
        string passcode;
        string widgetName;

        switch (rpc_type) {
            case CLRPC.RPC_SERVER_SETCODE:
                {
                    Param2<ItemBase, string> dataSetCode;
                    if (!ctx.Read(dataSetCode)) { return; }

                    player = PlayerBase.Cast(target);

                    if (!player) { return; }

                    targetObject = dataSetCode.param1;
                    passcode = dataSetCode.param2;

                    codelock = CodeLock.Cast(targetObject.GetCodeLock());

                    if (codelock && !GetCLPermissionManager().CanChangePasscodes(sender.GetPlainId()) && !codelock.HasNoOwner() && !codelock.IsOwner(sender.GetId())) {
                        GetCodeLockLogger().WriteLog("access", sender, codelock.GetPosition(), "notowner");
                    } else {
                        SetCode(targetObject, passcode);
                    }
                    break;
                }
            case CLRPC.RPC_SERVER_ENTERCODE:
                {
                    Param3<ItemBase, string, string> dataEnterCode;
                    if (!ctx.Read(dataEnterCode)) { return; }

                    player = PlayerBase.Cast(target);

                    if (!player) { return; }

                    targetObject = dataEnterCode.param1;
                    passcode = dataEnterCode.param2;
                    widgetName = dataEnterCode.param3;

                    EnterCode(targetObject, passcode, widgetName);
                    break;
                }
            case CLRPC.RPC_SERVER_ADMINMENU:
                {
                    Param2<ItemBase, string> dataAdmin;
                    if (!ctx.Read(dataAdmin)) { return; }

                    player = PlayerBase.Cast(target);

                    if (!player) { return; }

                    targetObject = dataAdmin.param1;
                    widgetName = dataAdmin.param2;

                    AdminMenu(targetObject, widgetName);
                    break;
                }
            case CLRPC.RPC_SERVER_CLAIMCODE:
                {
                    Param2<CodeLock, string> dataClaimCode;
                    if (!ctx.Read(dataClaimCode)) { return; }

                    player = PlayerBase.Cast(target);

                    if (!player) { return; }

                    codelock = dataClaimCode.param1;
                    passcode = dataClaimCode.param2;

                    ClaimCode(codelock, passcode);
                }
            case CLRPC.RPC_SERVER_SYNCHLOCK:
                {
                    codelock = CodeLock.Cast(target);

                    if (!codelock) return;
                    if (codelock.HasNoOwner()) return;

                    GetCodeLockLogger().WriteLog("synch", sender, codelock.GetPosition());
                    SendSynchCodeLockRPC(codelock, sender);
                    break;
                }
        }
    }

    private void SetCode(ItemBase itembase, string passcode) {
        CodeLock codelock = CodeLock.Cast(itembase.GetCodeLock());

        if (codelock) {
            if (codelock.HasNoOwner()) {
                GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "setcode");
                GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "claimowner");

                codelock.ServerSetOwner(player.GetIdentity().GetId());
            } else {
                GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "changecode");

                codelock.ServerClearGuests();
            }
            codelock.LockServer(itembase, passcode);
        }
    }

    private void EnterCode(ItemBase target, string passcode, string widget) {
        CodeLock codelock = CodeLock.Cast(target.GetCodeLock());
        bool isOwner = codelock.IsOwner(player.GetIdentity().GetId());

        if (!codelock.IsLocked(passcode)) {
            SendMenuError("exit");

            switch (widget) {
                case "btnEnterPin":
                    {
                        codelock.ServerSetOwner(player.GetIdentity().GetId());
                        GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "entercode");
                        LogOwner(codelock);
                        OpenTarget(target);
                        break;
                    }
                case "btnRemove":
                    {
                        if (!isOwner) { return; }

                        GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "removelock");
                        codelock.NewUnlockServer(player, target);
                        break;
                    }
                case "btnChangePin":
                    {
                        if (!isOwner) { return; }

                        SendShowSetCodeRPC(target);
                        break;
                    }
            }
        } else {
            SendMenuError("passcode");
        }
    }

    protected void AdminMenu(ItemBase target, string widgetName) {
        CodeLock codelock = CodeLock.Cast(target.GetCodeLock());

        switch (widgetName) {
            case "btnOpen":
                {
                    if (GetCLPermissionManager().CanOpenLocks(player.GetIdentity().GetPlainId())) {
                        SendMenuError("exit");
                        OpenTarget(target);
                        GetCodeLockLogger().WriteLog("admin", player.GetIdentity(), codelock.GetPosition(), "open");
                    } else {
                        SendMenuError("admin");
                    }
                    break;
                }
            case "btnChange":
                {
                    if (GetCLPermissionManager().CanChangePasscodes(player.GetIdentity().GetPlainId())) {
                        SendShowSetCodeRPC(target);
                        GetCodeLockLogger().WriteLog("admin", player.GetIdentity(), codelock.GetPosition(), "change");
                    } else {
                        SendMenuError("admin");
                    }
                    break;
                }
            case "btnRemove":
                {
                    if (GetCLPermissionManager().CanRemoveLocks(player.GetIdentity().GetPlainId())) {
                        SendMenuError("exit");
                        codelock.NewUnlockServer(player, target);
                        GetCodeLockLogger().WriteLog("admin", player.GetIdentity(), codelock.GetPosition(), "remove");
                    } else {
                        SendMenuError("admin");
                    }
                    break;
                }
        }
    }

    private void OpenTarget(ItemBase target) {
        Fence fence = Fence.Cast(target);

        if (fence) {
            fence.OpenFence();
            return;
        }
        TentBase tent = TentBase.Cast(target);

        if (tent) {
            tent.ToggleAnimation("entrancec");
            return;
        }
    }

    private void ClaimCode(CodeLock codelock, string passcode) {
        if (!codelock) return;
        if (codelock.HasNoOwner()) {
            if (!codelock.IsLocked(passcode)) {
                codelock.ServerSetOwner(player.GetIdentity().GetId());
                SendMenuError("exit");
                return;
            }
            SendMenuError("passcode");
            return;
        }
        SendMenuError("owner");
    }

    private void LogOwner(CodeLock codelock) {
        if (codelock.HasNoOwner()) {
            GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "claimowner");
        } else {
            GetCodeLockLogger().WriteLog("access", player.GetIdentity(), codelock.GetPosition(), "addguest");
        }
    }

    private void SendMenuError(string errorType) {
        auto params = new Param1<string>(errorType);
        GetGame().RPCSingleParam(player, CLRPC.RPC_CLIENT_HANDLEUI, params, true, player.GetIdentity());
    }

    private void SendShowSetCodeRPC(ItemBase target) {
        auto params = new Param1<ItemBase>(target);
        GetGame().RPCSingleParam(player, CLRPC.RPC_CLIENT_SHOWMENU, params, true, player.GetIdentity());
    }

    private void SendSynchCodeLockRPC(CodeLock codelock, PlayerIdentity sender) {
        auto params = new Param2<string, ref array<string>>(codelock.GetOwner(), codelock.GetGuests());

        GetGame().RPCSingleParam(codelock, CLRPC.RPC_CLIENT_SYNCHLOCK, params, true, sender);
    }
}
CodeLockServerRPC GetCLServerRPCHandler() {
    if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return null; }
    return CodeLockServerRPC.Cast(GetPlugin(CodeLockServerRPC));
}