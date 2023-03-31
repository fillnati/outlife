//Made by Pechyvo
class CfgPatches
{
	class CarParts
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
	//Car Parts
	class CarRadiator: Inventory_Base
	{
		scope=2;
		repairableWithKits[]={8};
		repairCosts[]={50};
	};
	class SparkPlug: Inventory_Base
	{
		scope=2;
		repairableWithKits[]={7};
		repairCosts[]={25};
	};
	class GlowPlug: Inventory_Base
	{
		scope=2;
		repairableWithKits[]={7};
		repairCosts[]={50};
	};
};