class CfgPatches {
	class IMP_Tag_Chevron {
		units[] = {"Shirt_CheckRed", "Hoodie_Blue", "Hoodie_Black", "Hoodie_Brown", "Hoodie_Green", "Hoodie_Grey", "Hoodie_Red", "MaleTorso", "FemaleTorso"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};

class CfgVehicles {
	class Inventory_Base;
	class Armband_Yellow;
	class Sweater_Gray;
	class LeatherBelt_Beige;
	
	class IMP_Chevron_ColorBase : LeatherBelt_Beige {
		scope = 0;
		displayName = "$STR_IMP_TAG";
		descriptionShort = "$STR_IMP_TAG";
		model = "IMPTAG\Chevron\models\Chevron_g.p3d";
		vehicleClass = "Clothing";
		simulation = "clothing";
		itemsCargoSize[] = {1, 2};
		inventorySlot = "Armband";
		attachments[] = {};
		itemInfo[] = {"Clothing", "Hips"};
		itemSize[] = {2, 1};
		weight = 200;
		lootCategory = "Crafted";
		lootTag[] = {"Civilian"};
		hiddenSelections[] = {"camoflage"};
		hiddenSelectionsMaterials[] = {"IMPTAG\Chevron\data\TAG_Material.rvmat"};
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG.paa"};
		
		class DamageSystem {
			class GlobalHealth {
				class Health {
					hitpoints = 800;
					healthLevels[] = {{1.01, {"DZ\characters\belts\data\belt_leather_beige.rvmat"}}, {0.7, {}}, {0.5, {"DZ\characters\belts\data\belt_leather_beige_damage.rvmat"}}, {0.3, {}}, {0.01, {"DZ\characters\belts\data\belt_leather_beige_destruct.rvmat"}}};
				};
			};
		};
		
		class ClothingTypes {
			male = "IMPTAG\Chevron\models\Chevron.p3d";
			female = "IMPTAG\Chevron\models\Chevron.p3d";
		};
	};
	
	class IMP_Chevron_Clear : IMP_Chevron_ColorBase {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG.paa"};
	};
	class IMP_Chevron_MONOLIT : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_MONOLIT.paa"};
	}; 
    class IMP_Chevron_HYDRA : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_HYDRA.paa"};
	};
    class IMP_Chevron_UA : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_UA.paa"};
	};
    class IMP_Chevron_Overlord : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_Overlord.paa"};
	};
	class IMP_Chevron_Corsair : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_Corsair.paa"};
	};
	class IMP_Chevron_STIX : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_STIX.paa"};
	};
	class IMP_Chevron_Jem : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_Jem.paa"};
	};
	class IMP_Chevron_Jem2 : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_Jem2.paa"};
	};
	class IMP_Chevron_A : IMP_Chevron_Clear {
		scope = 2;
		hiddenSelectionsTextures[] = {"IMPTAG\Chevron\data\TAG_A.paa"};
	};
};