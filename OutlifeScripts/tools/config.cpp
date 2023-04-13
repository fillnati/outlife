//Made by Pechyvo
class CfgPatches
{
	class Tools
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Tools"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	//Repairing Kits
	class WeaponCleaningKit: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class SewingKit: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class LeatherSewingKit: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class ElectronicRepairKit: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class EpoxyPutty: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class Whetstone: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class DuctTape: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
	class TireRepairKit: Inventory_Base
	{
		canBeSplit=1;
		weight=0.0099999998;
	};
};