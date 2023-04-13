//Made by Pechyvo
class CfgPatches
{
	class OutlifeScripts
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
class CfgMods
{
	class OutlifeScripts
	{
		name = "Outlife Crafts";
		credits="Dumpgrah,Daemon,Shinsasu";
		author = "Pechyvo";
		type = "mod";
		dependencies[]={"World"};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"OutlifeScripts/scripts/4_world"};
			};
		};
	};
};