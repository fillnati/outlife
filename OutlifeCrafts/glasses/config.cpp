//Made by Pechyvo
class CfgPatches
{
	class Glasses
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
	//NVG Headstrap
	class NVGHeadstrap: Inventory_Base
	{
		scope=2;
		repairableWithKits[]={8};
		repairCosts[]={50};
	};
};