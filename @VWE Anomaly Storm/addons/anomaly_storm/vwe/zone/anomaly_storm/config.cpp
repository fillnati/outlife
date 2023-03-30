////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.24
//https://mikero.bytex.digital/Downloads
//'now' is Thu Mar 30 19:14:08 2023 : 'file' last modified on Fri Mar 24 19:41:46 2023
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class VWE_Zone_Anomaly_Storm
	{
		author = "Virtual World Engineering";
		url = "";
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","VWE_Zone_Anomaly_Storm_Data","vwe_zone_broadcasting"};
		version = "8.3";
	};
};
class CfgMods
{
	class VWE_Zone_Anomaly_Storm
	{
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"vwe/zone/anomaly_storm/scripts/Common","vwe/zone/anomaly_storm/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"vwe/zone/anomaly_storm/scripts/Common","vwe/zone/anomaly_storm/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"vwe/zone/anomaly_storm/scripts/Common","vwe/zone/anomaly_storm/scripts/5_Mission"};
			};
		};
	};
};
