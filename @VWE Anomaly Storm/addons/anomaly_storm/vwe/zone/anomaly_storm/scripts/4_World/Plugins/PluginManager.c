modded class PluginManager
{
	override void Init()
	{
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin( "PluginEventAnomalyStorm",				true, 	true );
		
		super.Init();
	}
}