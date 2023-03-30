////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.24
//https://mikero.bytex.digital/Downloads
//'now' is Thu Mar 30 18:34:17 2023 : 'file' last modified on Thu Mar 30 18:34:17 2023
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class vwe_zone_broadcasting
	{
		author = "Virtual World Engineering";
		name = "vwe_zone_broadcasting";
		url = "";
		units[] = {"Zone_Radio_01"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Radio"};
		version = "1.0";
	};
};
class CfgMods
{
	class vwe_zone_broadcasting
	{
		author = "Virtual World Engineering";
		type = "mod";
		dependencies[] = {"World","Mission"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"vwe/zone/broadcasting/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"vwe/zone/broadcasting/scripts/5_Mission"};
			};
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	class ZoneRadioBase: HouseNoDestruct
	{
		displayName = "ZoneRadioBase";
	};
	class Zone_Radio_01: ZoneRadioBase
	{
		scope = 2;
		displayName = "Zone_Radio_01";
		model = "\vwe\zone\broadcasting\devices\radios\zone_radio_01\zone_radio_01.p3d";
	};
};
