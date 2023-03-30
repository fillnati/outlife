//Made by Pechyvo
class CfgPatches
{
	class Ol_Cassette_VV
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Ol_BaseCassette;
	class Ol_VV_Cassette: Ol_BaseCassette
	{
		scope=2;
		displayName="Касета з підписом";
		descriptionShort="По надпису можна зрозуміти, що це касети групи ВВ.";
		hiddenSelectionsTextures[]=
		{
			"OutlifeRadio\Cassettes\VV_Cassette\VV.paa"
		};
	};
};
class CfgSoundSets
{
	class Mods_SoundSet_Base;
	class VV_Cassette_SoundSet: Mods_SoundSet_Base
	{
		soundShaders[]=
		{
			"VV_Cassette_SoundShader"
		};
		frequencyRandomizer=0;
		volumeRandomizer=0;
	};
};
class CfgSoundShaders
{
	class Mods_SoundShader_Base;
	class VV_Cassette_SoundShader: Mods_SoundShader_Base
	{
		samples[]=
		{
			
			{
				"OutlifeRadio\Cassettes\VV_Cassette\VV.ogg",
				1
			}
		};
		volume=0.69999999;
	};
};
