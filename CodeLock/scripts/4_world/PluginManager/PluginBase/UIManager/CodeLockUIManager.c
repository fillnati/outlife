class CodeLockUIManager : PluginBase {
    void ShowMenu(int menuId, ItemBase target) {
        if (GetGame().IsServer()) { return; }
        if (GetGame().GetUIManager().GetMenu()) {
            return;
        }
        GetGame().GetUIManager().EnterScriptedMenu(menuId, null);

        CodeLockMenu menu = CodeLockMenu.Cast(GetGame().GetUIManager().GetMenu());
        menu.SetTarget(target);
    }

    void ShowMenuError(string errorType) {
        CodeLockMenu menu = CodeLockMenu.Cast(GetGame().GetUIManager().GetMenu());
        errorType.ToLower();

        if (menu) {
            menu.ShowCLMenuError(errorType);
        }
    }

    void ExitMenus() {
        CodeLockMenu menu = CodeLockMenu.Cast(GetGame().GetUIManager().GetMenu());

        if (menu) {
            menu.Close();
        }
    }
}
CodeLockUIManager GetCLUIManager() {
    return CodeLockUIManager.Cast(GetPlugin(CodeLockUIManager));
}