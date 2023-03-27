class AdminCodeMenu : CodeLockMenu {
	private ref array<string> btnNames = { "btnChange", "btnOpen", "btnRemove" };

	override Widget Init() {
		if (!IsInitialized()) {
			wRoot = GetGame().GetWorkspace().CreateWidgets("CodeLock\\gui\\layouts\\adminComboCode.layout");
			txtTitle = TextWidget.Cast(wRoot.FindAnyWidget("txtEnterPin"));
			SetInitialized();
		}
		return wRoot;
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		bool canContinue = super.OnClick(w, x, y, button);

		if (button == MouseState.LEFT) {
			if (!canContinue) {
				string widgetName = w.GetName();
				int btnIndex = btnNames.Find(widgetName);

				if (btnIndex != -1) {
					if (GetDayZGame().CLIsUIRateLimited()) {
						ShowCLMenuError("rate");
						return true;
					}
					switch (btnIndex) {
						case 0:
							{
								if (GetCLPermissionManager().CanChangePasscodes()) {
									SendRPC(widgetName);
								} else {
									ShowCLMenuError("admin");
								}
								break;
							}
						case 1:
							{
								if (GetCLPermissionManager().CanOpenLocks()) {
									SendRPC(widgetName);
								} else {
									ShowCLMenuError("admin");
								}
								break;
							}
						case 2:
							{
								if (GetCLPermissionManager().CanRemoveLocks()) {
									SendRPC(widgetName);
								} else {
									ShowCLMenuError("admin");
								}
								break;
							}
					}
					return true;
				}
			}
		}
		return false;
	}

	void SendRPC(string widgetName) {
		auto params = new Param2<ItemBase, string>(target, widgetName);
		GetGame().RPCSingleParam(player, CLRPC.RPC_SERVER_ADMINMENU, params, true);
		GetDayZGame().SetCLUIRateLimit();
	}

	override void OnHide() {
		super.OnHide();
		txtTitle.SetText("ADMIN MENU");
	}

	override void ShowCLMenuError(string errorType) {
		string error;

		super.ShowCLMenuError(errorType);

		switch (errorType) {
			case "admin":
				{
					error = "INVALID PERMS!";
					break;
				}
		}
		if (error != string.Empty) {
			txtTitle.SetText(error);
		}
	}
}