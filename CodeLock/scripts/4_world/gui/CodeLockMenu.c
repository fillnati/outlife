class CodeLockMenu : UIScriptedMenu {
	protected ref Widget wRoot;
	protected ref EditBoxWidget boxEditPin;
	protected ref TextWidget txtTitle;
	protected ItemBase target;
	protected PlayerBase player;
	protected int isInitialized;
	protected string passPlainText;

	void ShowCLMenuError(string errorType) {
		string error;
		switch (errorType) {
			case "short":
			{
				error = "TOO SHORT";
				break;
			}
			case "rate":
			{
				error = "RATE LIMITED!";
				break;
			}
			case "passcode":
			{
				error = "INVALID PASSCODE!";
				break;
			}
		}
		txtTitle.SetText(error);
	}

	void SendRPC() {}

	void CheckState() {}

	void SetTarget(ItemBase targetObject) {
		target = targetObject;
	}

    protected void SetInitialized() {
        isInitialized = true;
    }

    protected bool IsInitialized() {
        return isInitialized;
    }

	protected string ConsealText(string input) {
		string consealedtext = string.Empty;

		for (int i = 0; i < input.Length(); i++) {
			consealedtext += "*";
		}

		return consealedtext;
	}

	override bool OnKeyPress(Widget w, int x, int y, int key) {
		if (w.GetName() == "edtPinCode") {
			string boxText = boxEditPin.GetText();
			if (boxText.Length() >= 6) {
				boxEditPin.SetText(boxText);
				return true;
			}
		}
		return false;
	}

	override bool OnClick(Widget w, int x, int y, int button) {
		super.OnClick(w, x, y, button);
		
		if (button == MouseState.LEFT) {
			string widgetName = w.GetName();

			if (widgetName == "btnCancelPin") {
				GetGame().GetUIManager().HideScriptedMenu(this);
				return true;
			}
		} else {
			int textLength = boxEditPin.GetText().Length();
			if (textLength < 3) {
				ShowCLMenuError("short");
				return true;
			}
		}
		return false;
	}

	override bool OnChange(Widget w, int x, int y, bool finished) {
		super.OnChange(w, x, y, finished);
		if (w.GetName() == "edtPinCode") {
			string boxText = boxEditPin.GetText();
			int boxLength = boxText.Length();
			int codeLength = passPlainText.Length();

			if (boxLength > codeLength) {
				passPlainText += boxText.Substring(codeLength, 1);
			} else {
				passPlainText = passPlainText.Substring(0, boxLength);
			}
			boxEditPin.SetText(ConsealText(boxText));
			return true;
		}
		return false;
	}

	override void OnShow() {
		super.OnShow();

		GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
		GetGame().GetUIManager().ShowCursor(true);
		GetGame().GetMission().GetHud().Show(false);
		player = PlayerBase.Cast(GetGame().GetPlayer());
	}

	override void OnHide() {
		super.OnHide();

		GetGame().GetUIManager().ShowCursor(false);
		GetGame().GetMission().PlayerControlEnable(1);
		GetGame().GetMission().GetHud().Show(true);
	}
}