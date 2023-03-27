class CfgPatches
{
	class EventJammer
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
	class EventJammer
	{
		dir="EventJammer";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="EventJAmmer";
		credits="";
		author="Fillnati; Filin; DaphCookie";
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
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"EventJamemr\scripts\4_Game"
				};
			};
            class worldScriptModule
			{
				value="";
				files[]=
				{
					"EventJamemr\scripts\4_World"
				};
			};
            class missionScriptModule
			{
				value="";
				files[]=
				{
					"EventJamemr\scripts\4_Mission"
				};
			};
		};
	};
};