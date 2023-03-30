//Made by Pechyvo
class Ol_Static_TarasChubay_Milga extends BuildingSuper
{
protected ref EffectSound Ol_TarasChubaySound;
	
   
    void Ol_Static_TarasChubay_Milga()
    {
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{		
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitTarasChubay, 15, false);
		}   
    }
    


	void InitTarasChubay()
	{
		PlaySoundSetLoop( Ol_TarasChubaySound, "TarasChubay_Cassette_SoundSet", 0, 0 );
		Ol_TarasChubaySound.SetSoundLoop(true);
		Ol_TarasChubaySound.SetSoundAutodestroy( true );
	}
};
class Ol_Static_VV_Milga extends BuildingSuper
{
protected ref EffectSound Ol_VVSound;
	
   
    void Ol_Static_VV_Milga()
    {
		if ( GetGame().IsClient()  ||  !GetGame().IsMultiplayer() )
		{		
			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(InitVV, 15, false);
		}   
    }
    


	void InitVV()
	{
		PlaySoundSetLoop( Ol_VVSound, "VV_Cassette_SoundSet", 0, 0 );
		Ol_VVSound.SetSoundLoop(true);
		Ol_VVSound.SetSoundAutodestroy( true );
	}
};