class CfgPatches
{
	class Ol_BatteryForRadio
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Medical"
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Battery9V: Inventory_Base
	{
		scope=2;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\consumables\data\9v_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\consumables\data\9v.rvmat"
		};
	};
	class Ol_Camelion9V: Battery9V
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"OutlifeRadio\Battery\data\Camelion_co.paa"
		};
		class EnergyManager
		{
			hasIcon=1;
			switchOnAtSpawn=1;
			isPassiveDevice=1;
			energyStorageMax=150;
			energyAtSpawn=150;
			convertEnergyToQuantity=1;
			reduceMaxEnergyByDamageCoef=1;
			powerSocketsCount=1;
			compatiblePlugTypes[]={1};
		};
	};
};
