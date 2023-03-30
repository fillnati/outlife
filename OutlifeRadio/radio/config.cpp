//Made by Pechyvo
class CfgPatches
{
	class Ol_Radio_Base
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
	class Inventory_Base;
	class Ol_BaseRadio: Inventory_Base
	{
		scope=0;
		animClass="Knife";
		fragility=0.0099999998;
		absorbency=0.5;
		attachments[]=
		{
			"BatteryD",
			"Ol_BaseCassette"
		};
		hiddenSelections[]=
		{
			"camo"
		};
		oldpower=0;
		repairableWithKits[]={5,7};
		repairCosts[]={30,25};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\radio\data\unitra_wilga.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\radio\data\unitra_wilga.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\radio\data\unitra_wilga_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\radio\data\unitra_wilga_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\radio\data\unitra_wilga_destruct.rvmat"
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
	class Ol_Vesna_Radio: Ol_BaseRadio
	{
		scope=2;
		displayName="Весна - 207 - стерео";
		descriptionShort="Портативний касетний магнітофон «Весна-207-стерео» з 1982 випускав Запорізький ЕМЗ «Iскра». Модель призначена для запису на магнітну стрічку моно або стереофонічних фонограм та їх подальшого відтворення у монофонічному режимі вбудованим гучномовцем, а у стереофонічному зовнішнім УКУ.";
		model="OutlifeRadio\Radio\vesna.p3d";
		itemSize[]={4,4};
		weight=1700;
		hiddenSelectionsTextures[]=
		{
			"OutlifeRadio\Radio\data\vesna\radio_co.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.029999999;
			attachmentAction=1;
			wetnessExposure=0.1;
		};
	};
	class Ol_Milga_Radio: Ol_BaseRadio
	{
		scope=2;
		displayName="Milga Fm 301";
		descriptionShort="Різновид магнітофона, в якій магнітна стрічка разом з частиною стрічкопротяжного тракту розташовується в швидкознімній касеті, що спрощує перезаряджання.";
		model="dz\gear\radio\unitra_wilga.p3d";
		itemSize[]={4,3};
		weight=1000;
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.02;
			attachmentAction=1;
			wetnessExposure=0.1;
		};
	};
	class Ol_Panasonic_Radio: Ol_BaseRadio
	{
		scope=2;
		displayName="Panasonic RF-2400D";
		descriptionShort="Простий FM/AM радіоприймач має універсальний дизайн для зручного перегляду та оснащений новим цифровим тюнером, що забезпечує легке налаштування та стійкий прийом. Він може працювати від мережі через адаптер змінного струму або від батареї, що дозволяє користуватися ним як у приміщенні, так і на вулиці.";
		model="OutlifeRadio\Radio\panasonic.p3d";
		itemSize[]={3,2};
		weight=690;
		hiddenSelectionsTextures[]=
		{
			"OutlifeRadio\Radio\data\panasonic\miniradio_co.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			autoSwitchOff=1;
			energyUsagePerSecond=0.0099999998;
			attachmentAction=1;
			wetnessExposure=0.1;
		};
	};
};
class CfgSlots
{
	class Ol_Universal_CasetteSlot
	{
		name="Ol_BaseCassette";
		displayName="Вставити касету";
		ghostIcon="default";
	};
};
