class CodeLockClientRPC : PluginBase {
    void CodeLockClientRPC() {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) { return; }

        GetDayZGame().Event_OnRPC.Insert(ClientRPCHandler);
    }

    void ~CodeLockClientRPC() {
        GetDayZGame().Event_OnRPC.Remove(ClientRPCHandler);
    }

    void ClientRPCHandler(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            delete this;
            return;
        }
        ItemBase targetObject;
        CodeLock codelock;

        switch (rpc_type) {
            case CLRPC.RPC_CLIENT_SYNCHLOCK:
                {
                    Param2<string, ref array<string>> dataSynchLock;
                    if (!ctx.Read(dataSynchLock)) { return; }

                    codelock = CodeLock.Cast(target);
                    string ownerId = dataSynchLock.param1;
                    ref array<string> arrayGuests = dataSynchLock.param2;

                    if (!codelock) return;
                    codelock.SynchLock(ownerId, arrayGuests);
                    break;
                }
            case CLRPC.RPC_CLIENT_SHOWMENU:
                {
                    Param1<ItemBase> dataSetCode;
                    if (!ctx.Read(dataSetCode)) { return; }

                    targetObject = dataSetCode.param1;

                    GetCLUIManager().ExitMenus();
                    GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(GetCLUIManager().ShowMenu, 50, false, CLMENU.SET_CODE_MENU, targetObject);
                    break;
                }
            case CLRPC.RPC_CLIENT_HANDLEUI:
                {
                    Param1<string> dataErrorType;
                    if (!ctx.Read(dataErrorType)) { return; }

                    string errorType = dataErrorType.param1;
                    errorType.ToLower();

                    if (errorType == "exit") {
                        GetCLUIManager().ExitMenus();
                    } else {
                        GetCLUIManager().ShowMenuError(errorType);
                    }
                    break;
                }
            case CLRPC.RPC_CLIENT_SETCONFIG:
                {
                    Param1<CodeLockConfig> dataConfig;
                    ctx.Read(dataConfig);

                    CodeLockConfig config = dataConfig.param1;

                    if (!config) {
                        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().DisconnectSessionForce, 100, false);
                        return;
                    }

                    GetDayZGame().SetCodeLockConfig(config);
                    break;
                }
            case CLRPC.RPC_CLIENT_SYNCHADMINS:
                {
                    Param2<ref array<ref CodeLockAdmin>, string> dataAdmins;
                    ctx.Read(dataAdmins);

                    ref array<ref CodeLockAdmin> arrayAdmins = dataAdmins.param1;
                    string clientPlainId = dataAdmins.param2;

                    GetCLPermissionManager().SetClientAdmin(arrayAdmins, clientPlainId);
                    break;
                }
        }
    }
}