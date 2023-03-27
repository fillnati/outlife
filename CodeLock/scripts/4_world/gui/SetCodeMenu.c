class SetCodeMenu : CodeLockMenu {
    string codeSet;

    override Widget Init() {
        if (!IsInitialized()) {
            wRoot = GetGame().GetWorkspace().CreateWidgets("CodeLock\\gui\\layouts\\setComboCode.layout");
			txtTitle = TextWidget.Cast(wRoot.FindAnyWidget("txtEnterPin"));
			boxEditPin = EditBoxWidget.Cast(wRoot.FindAnyWidget("edtPinCode"));
            SetInitialized();
            //ClearInput();
        }
        return wRoot;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        bool canContinue = super.OnClick(w, x, y, button);

        if (button == MouseState.LEFT) {
            if (!canContinue) {
                string widgetName = w.GetName();

                if (widgetName == "btnEnterPin") {
                    CheckState();
                }
                return true;
            }
        }
        return false;
    }

    void CheckState() {
        string boxText = boxEditPin.GetText();

        if (boxText.Length() < 3) {
            ShowCLMenuError("short");
            return;
        }

        if (codeSet == string.Empty) {
            codeSet = passPlainText;
            passPlainText = string.Empty;
            boxEditPin.SetText(string.Empty);
            ShowCLMenuError("confirm");
            return;
        }
        
        if (passPlainText == codeSet) {
            if (GetDayZGame().CLIsUIRateLimited()) {
                ShowCLMenuError("rate");
                return;
            }
            auto params = new Param2<ItemBase, string>(target, codeSet);
            GetGame().RPCSingleParam(player, CLRPC.RPC_SERVER_SETCODE, params, true);
            GetGame().GetUIManager().HideScriptedMenu(this);
            GetDayZGame().SetCLUIRateLimit();
        } else if (passPlainText != codeSet) {
            ShowCLMenuError("match");
        }
    }

    override void OnHide() {
        super.OnHide();

        //ClearInput();
        txtTitle.SetText("SET PASSCODE");
    }

	override void ShowCLMenuError(string errorType) {
		string error;

		super.ShowCLMenuError(errorType);

		switch (errorType) {
			case "confirm":
			{
				error = "CONFIRM PASSCODE";
				break;
			}
			case "match":
			{
				error = "DOES NOT MATCH";
				break;
			}
		}
		if (error != string.Empty) {
			txtTitle.SetText(error);
		}
	}
}