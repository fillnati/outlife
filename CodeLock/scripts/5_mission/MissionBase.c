modded class MissionGameplay {
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = null;
        menu = super.CreateScriptedMenu(id);

        if (!menu) {
            switch (id) {
                case CLMENU.SET_CODE_MENU:
                    {
                        menu = new SetCodeMenu();
                        break;
                    }
                case CLMENU.GUEST_CODE_MENU:
                    {
                        menu = new GuestCodeMenu();
                        break;
                    }
                case CLMENU.ENTER_CODE_MENU:
                    {
                        menu = new EnterCodeMenu();
                        break;
                    }
                case CLMENU.ADMIN_CODE_MENU:
                    {
                        menu = new AdminCodeMenu();
                        break;
                    }
                case CLMENU.CLAIM_CODE_MENU:
                    {
                        menu = new ClaimCodeMenu();
                        break;
                    }
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }

    override void OnKeyPress(int key) {
        CodeLockMenu menu;
        
        if (key == KeyCode.KC_ESCAPE) {
            menu = CodeLockMenu.Cast(GetUIManager().GetMenu());

            if (menu) {
                menu.Close();
                return;
            }
        } else if (key == KeyCode.KC_RETURN || key == KeyCode.KC_NUMPADENTER) {
            menu = CodeLockMenu.Cast(GetUIManager().GetMenu());

            if (menu) {
                if (SetCodeMenu.Cast(menu)) {
                    menu.CheckState();
                } else {
                    menu.SendRPC();
                }
                return;
            }
        }
        super.OnKeyPress(key);
        m_Hud.KeyPress(key);
    }
}