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
	//BatteryCharger
	class BatteryCharger: Inventory_Base
	{
		scope=2;
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