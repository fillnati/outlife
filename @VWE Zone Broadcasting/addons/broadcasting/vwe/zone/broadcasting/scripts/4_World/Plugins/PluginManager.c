modded class PluginManager
{
	override void Init()
	{
		//----------------------------------------------------------------------
		// Register modules
		//----------------------------------------------------------------------
		//				Module Class Name 						Client	Server
		//----------------------------------------------------------------------
		RegisterPlugin( "PluginZoneBroadcasting",				true, 	false );
		
		super.Init();
	}
}