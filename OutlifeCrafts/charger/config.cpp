//Made by Pechyvo
class CfgPatches
{
	class Charger
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
	//BatteryCharger
	class BatteryCharger: Inventory_Base
	{
		attachments[]=
		{
			"LargeBattery",
			"BatteryD"
		};
		class EnergyManager
		{
			compatiblePlugTypes[]={4,1};
		};
	};
};