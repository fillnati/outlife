class ClaimCodeMenu : CodeLockMenu {
	override Widget Init() {
		if (!IsInitialized()) {
			wRoot = GetGame().GetWorkspace().CreateWidgets("CodeLock\\gui\\layouts\\claimComboCode.layout");
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
				if (w.GetName() == "btnEnterPin") {
					SendRPC();
					return true;
				}
			}
		}
		return false;
	}

	void SendRPC() {
		if (GetDayZGame().CLIsUIRateLimited()) {
			ShowCLMenuError("rate");
			return;
		}
		auto params = new Param2<CodeLock, string>(target.GetCodeLock(), passPlainText);
		GetGame().RPCSingleParam(player, CLRPC.RPC_SERVER_CLAIMCODE, params, true);
		GetDayZGame().SetCLUIRateLimit();
	}

	override void OnHide() {
		super.OnHide();
		txtTitle.SetText("ENTER PASSCODE");
	}

	override void ShowCLMenuError(string errorType) {
		string error;

		super.ShowCLMenuError(errorType);

		switch (errorType) {
			case "owner":
				{
					error = "OWNER ALREADY SET!";
					break;
				}
		}
		if (error != string.Empty) {
			txtTitle.SetText(error);
		}
	}
}