class CfgPatches
{
	class Ol_Cassette_TarasChubay
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
	class Ol_TarasChubay_Cassette: Ol_BaseCassette
	{
		scope=2;
		displayName="Касета з підписом";
		descriptionShort="За підписом на касеті можна припустити, що на ній записані пісні гурту Тарас Чубай.";
		hiddenSelectionsTextures[]=
		{
			"OutlifeRadio\Cassettes\TarasChubay_Cassette\TarasChubay.paa"
		};
	};
};
class CfgSoundSets
{
	class Mods_SoundSet_Base;
	class TarasChubay_Cassette_SoundSet: Mods_SoundSet_Base
	{
		soundShaders[]=
		{
			"TarasChubay_Cassette_SoundShader"
		};
		frequencyRandomizer=0;
		volumeRandomizer=0;
	};
};
class CfgSoundShaders
{
	class Mods_SoundShader_Base;
	class TarasChubay_Cassette_SoundShader: Mods_SoundShader_Base
	{
		samples[]=
		{
			
			{
				"OutlifeRadio\Cassettes\TarasChubay_Cassette\TarasChubay.ogg",
				1
			}
		};
		volume=0.69999999;
	};
};
