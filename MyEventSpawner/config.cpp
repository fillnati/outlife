class CfgPatches
{
	class MyEventSpawner
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class MyEventSpawner
	{
		dir="MyEventSpawner";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="MyEventSpawner";
		credits="";
		author="Fillnati";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
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
				value="";
				files[]=
				{
					"MyEventSpawner\scripts\3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"MyEventSpawner\scripts\3_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"MyEventSpawner\scripts\3_Mission"
				};
			};
		};
	};
};