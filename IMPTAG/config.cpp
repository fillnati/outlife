class CfgPatches 
{
	class IMPTAG 
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Medical", "DZ_Structures_Furniture", "DZ_Data", "DZ_Characters", "DZ_Scripts", "DZ_gear_food", "DZ_Gear_Consumables", "DZ_Characters_Vests", "DZ_Gear_Containers", "DZ_Weapons_Melee", "DZ_Weapons_Magazines"};
	};
};

class CfgMods {
	class IMPTAG {
		dir = IMPTAG;
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = IMPTAG;
		credits = IMPERIVM;
		author = IMPERIVM;
		authorID = "0";
		version = 0.1;
		extra = 0;
		type = "mod";
		dependencies[] = {"World", "Game", "Mission"};
		
		class defs {
			class gameScriptModule {
				value = "";
				files[] = {"IMPTAG\scripts\3_Game"};
			};
			
			class worldScriptModule {
				value = "";
				files[] = {"IMPTAG\scripts\4_World"};
			};
			
			class missionScriptModule {
				value = "";
				files[] = {"IMPTAG\scripts\5_Mission"};
			};
		};
	};
};
