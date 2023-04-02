//Made by Pechyvo
class CfgPatches
{
	class Attachments
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
	//Repairing Kits
	class WeaponCleaningKit: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class SewingKit: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class LeatherSewingKit: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class ElectronicRepairKit: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class EpoxyPutty: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class Whetstone: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class DuctTape: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
	class TireRepairKit: Inventory_Base
	{
		scope=2;
		canBeSplit=1;
	};
};