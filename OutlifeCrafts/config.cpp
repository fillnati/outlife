//Made by Pechyvo
class CfgPatches
{
	class OutlifeCrafts
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
	class OutlifeCrafts
	{
		name = "Outlife Crafts";
		credits = "";
		author = "Pechyvo";
		type = "mod";
		dependencies[]={"World"};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"OutlifeCrafts/scripts/4_world"};
			};
		};
	};
};