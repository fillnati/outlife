class CfgPatches
{
	class CodeLock
	{
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
		units[]={};
		weapons[]={};
	};
};
class CfgMods
{
	class CodeLock
	{
		type="mod";
		author="RoomService & Wardog";
		dir="CodeLock";
		name="CodeLock";
		dependencies[]=
		{
			"Game",
			"World",
			"Mission"
		};
		class defs
		{
			class gameScriptModule
			{
				files[]=
				{
					"CodeLock/scripts/Common",
					"CodeLock/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				files[]=
				{
					"CodeLock/scripts/Common",
					"CodeLock/scripts/4_world"
				};
			};
			class missionScriptModule
			{
				files[]=
				{
					"CodeLock/scripts/Common",
					"CodeLock/scripts/5_mission"
				};
			};
		};
	};
};
