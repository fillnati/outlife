class GuestCodeMenu : CodeLockMenu {
	override Widget Init() {
		if (!IsInitialized()) {
			wRoot = GetGame().GetWorkspace().CreateWidgets("CodeLock\\gui\\layouts\\guestComboCode.layout");
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
		auto params = new Param3<ItemBase, string, string>(target, passPlainText, "btnEnterPin");
		GetGame().RPCSingleParam(player, CLRPC.RPC_SERVER_ENTERCODE, params, true);
		GetDayZGame().SetCLUIRateLimit();
	}

	override void OnHide() {
		super.OnHide();

		//ClearInput();
		txtTitle.SetText("ENTER PASSCODE");
	}
}