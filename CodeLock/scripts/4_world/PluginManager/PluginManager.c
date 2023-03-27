modded class PluginManager {
	override void Init() {
		super.Init();
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin("CodeLockLogger", false, true);
		RegisterPlugin("CodeLockPermissionManager", true, true);
		RegisterPlugin("CodeLockClientRPC", true, false);
		RegisterPlugin("CodeLockServerRPC", false, true);
		RegisterPlugin("CodeLockUIManager", true, false);
	}
}