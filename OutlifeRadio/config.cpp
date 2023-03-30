//Made by Pechyvo
class CfgPatches
{
	class OutlifeRadio
	{
		units[]={};
		ammo[]={};
		weapons[]={};
		magazines[]={};
		requiredVersion=0.1;
		requiredAddons[]={};
		Ultima_Version=0.1;
	};
};
class CfgMods
{
	class OutlifeRadio
	{
		name="OutlifeRadio";
		credits="";
		author="";
		type="mod";
		dependencies[]={"World"};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]={"OutlifeRadio/scripts/4_World"};
			};
		};
	};
};
