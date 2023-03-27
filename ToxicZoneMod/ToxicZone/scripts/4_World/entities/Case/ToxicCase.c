class ToxicCase extends Container_Base
{
	void ToxicCase()
	{
		
	}
	
	void ~ToxicCase()
	{
		
	}
	
	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
}