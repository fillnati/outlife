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
			"World",
			"Game",
			"Mission"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"MyEventSpawner\scripts\4_World"
				};
			};
		};
	};
};