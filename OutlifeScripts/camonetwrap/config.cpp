//Edited By Pechyvo
// All credits to SSM_CamoNetWrap
class CfgPatches
{
	class CamonetWrap
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Weapons_Supports",
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
class Inventory_Base;
class GhillieAtt_ColorBase: Inventory_Base{};
class Ol_CamoNetWrap: GhillieAtt_ColorBase
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"OutlifeScripts\camonetwrap\data\weapon_netcamo_co.paa"
		};
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
								"OutlifeScripts\camonetwrap\data\weapon_netcamo_co.paa"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"OutlifeScripts\camonetwrap\data\weapon_netcamo_co.paa"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"OutlifeScripts\camonetwrap\data\weapon_netcamo_co.paa"
							}
						}
					};
				};
			};
		};
	};
};