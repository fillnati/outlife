class CfgPatches
{
	class OutLife_Music
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
	class Cassette;
	class Ol_BaseCassette: Cassette
	{
		scope=2;
		displayName="Порожня касета";
		descriptionShort="Касета без підпису, швидше за все, порожня.";
		model="OutlifeRadio\Cassettes\Base\cassette.p3d";
		inventorySlot="Ol_BaseCassette";
		rotationFlags=17;
		weight=80;
		absorbency=0.5;
		itemSize[]={2,1};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"OutlifeRadio\Cassettes\Base\data\CassetteClear1_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=10;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\tools\data\cassette.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\tools\data\cassette.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\tools\data\cassette_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\tools\data\cassette_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\tools\data\cassette_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=2.8;
			};
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyCassette: ProxyAttachment
	{
		scope=2;
		inventorySlot="Ol_BaseCassette";
		model="OutlifeRadio\Cassettes\Base\cassette.p3d";
	};
};
class CfgSoundSets
{
	class Mods_SoundSet_Base
	{
		sound3DProcessingType="character3DProcessingType";
		volumeCurve="characterAttenuationCurve";
		spatial=1;
		doppler=0;
		loop=0;
	};
	class Empty_Cassette_SoundSet: Mods_SoundSet_Base
	{
		soundShaders[]=
		{
			"Empty_Cassette_SoundShader"
		};
		frequencyRandomizer=0;
		volumeRandomizer=0;
	};
};
class CfgSoundShaders
{
	class Mods_SoundShader_Base
	{
		range=30;
	};
	class Empty_Cassette_SoundShader: Mods_SoundShader_Base
	{
		samples[]=
		{
			
			{
				"OutlifeRadio\Cassettes\Base\Empty.ogg",
				1
			}
		};
		volume=0.69999999;
	};
};
