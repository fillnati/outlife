class CraftMetalSheet extends RecipeBase
{	
	override void Init()
	{
		m_Name = "Порізати на Метал";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 2;//animation length in relative time units
		m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = 2;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Hacksaw");//you can insert multiple ingredients this way
	
		m_IngredientAddHealth[0] = -25;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = true;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"CivSedanDoors_Driver");//you can insert multiple ingredients this way
		InsertIngredient(1,"CivSedanDoors_CoDriver");
		InsertIngredient(1,"CivSedanDoors_BackLeft");
		InsertIngredient(1,"CivSedanDoors_BackRight");
		InsertIngredient(1,"CivSedanDoors_Driver_Wine");
		InsertIngredient(1,"CivSedanDoors_CoDriver_Wine");
		InsertIngredient(1,"CivSedanDoors_BackLeft_Wine");
		InsertIngredient(1,"CivSedanDoors_BackRight_Wine");
		InsertIngredient(1,"CivSedanDoors_Driver_Black");
		InsertIngredient(1,"CivSedanDoors_CoDriver_Black");
		InsertIngredient(1,"CivSedanDoors_BackLeft_Black");
		InsertIngredient(1,"CivSedanDoors_BackLeft_Black");
		InsertIngredient(1,"CivSedanDoors_BackRight_Black");
		InsertIngredient(1,"CivSedanDoors_Driver_WhiteRust");
		InsertIngredient(1,"CivSedanDoors_CoDriver_WhiteRust");
		InsertIngredient(1,"CivSedanDoors_BackLeft_WhiteRust");
		InsertIngredient(1,"CivSedanDoors_BackRight_WhiteRust");
		InsertIngredient(1,"CivSedanDoors_Driver_WineRust");
		InsertIngredient(1,"CivSedanDoors_CoDriver_WineRust");
		InsertIngredient(1,"CivSedanDoors_BackLeft_WineRust");
		InsertIngredient(1,"CivSedanDoors_BackRight_WineRust");
		InsertIngredient(1,"CivSedanDoors_Driver_BlackRust", );
		InsertIngredient(1,"CivSedanDoors_CoDriver_BlackRust");
		InsertIngredient(1,"CivSedanDoors_BackLeft_BlackRust");
		InsertIngredient(1,"CivSedanDoors_BackLeft_BlackRust");
		InsertIngredient(1,"CivSedanDoors_BackRight_BlackRust");
		InsertIngredient(1,"Sedan_02_Door_1_1");
		InsertIngredient(1,"Sedan_02_Door_2_1");
		InsertIngredient(1,"Sedan_02_Door_1_2");
		InsertIngredient(1,"Sedan_02_Door_2_2");
		InsertIngredient(1,"Sedan_02_Door_1_1_Red");
		InsertIngredient(1,"Sedan_02_Door_2_1_Red");
		InsertIngredient(1,"Sedan_02_Door_1_2_Red");
		InsertIngredient(1,"Sedan_02_Door_2_2_Red");
		InsertIngredient(1,"Sedan_02_Door_2_2_Red");
		InsertIngredient(1,"Sedan_02_Door_1_1_Grey");
		InsertIngredient(1,"Sedan_02_Door_2_1_Grey");
		InsertIngredient(1,"Sedan_02_Door_1_2_Grey");
		InsertIngredient(1,"Sedan_02_Door_2_2_Grey");
		InsertIngredient(1,"Sedan_02_Door_1_1_YellowRust");
		InsertIngredient(1,"Sedan_02_Door_2_1_YellowRust");
		InsertIngredient(1,"Sedan_02_Door_1_2_YellowRust");
		InsertIngredient(1,"Sedan_02_Door_2_2_YellowRust");
		InsertIngredient(1,"Sedan_02_Door_1_1_RedRust");
		InsertIngredient(1,"Sedan_02_Door_2_1_RedRust");
		InsertIngredient(1,"Sedan_02_Door_1_2_RedRust");
		InsertIngredient(1,"Sedan_02_Door_2_2_RedRust");
		InsertIngredient(1,"Sedan_02_Door_2_2_RedRust");
		InsertIngredient(1,"Sedan_02_Door_1_1_GreyRust");
		InsertIngredient(1,"Sedan_02_Door_2_1_GreyRust");
		InsertIngredient(1,"Sedan_02_Door_1_2_GreyRust");
		InsertIngredient(1,"Sedan_02_Door_2_2_GreyRust");
		InsertIngredient(1,"Sedan_02_Hood");
		InsertIngredient(1,"Sedan_02_Hood_Red");
		InsertIngredient(1,"Sedan_02_Hood_Grey");
		InsertIngredient(1,"Sedan_02_Hood_YellowRust");
		InsertIngredient(1,"Sedan_02_Hood_RedRust");
		InsertIngredient(1,"Sedan_02_Hood_GreyRust");
		InsertIngredient(1,"CivSedanTrunk");
		InsertIngredient(1,"CivSedanTrunk_Wine");
		InsertIngredient(1,"CivSedanTrunk_Black");
		InsertIngredient(1,"CivSedanTrunk_WhiteRust");
		InsertIngredient(1,"CivSedanTrunk_WineRust");
		InsertIngredient(1,"CivSedanTrunk_BlackRust");
		InsertIngredient(1,"HatchbackDoors_Driver");
		InsertIngredient(1,"HatchbackDoors_CoDriver");
		InsertIngredient(1,"HatchbackDoors_Driver_Blue");
		InsertIngredient(1,"HatchbackDoors_CoDriver_Blue");
		InsertIngredient(1,"HatchbackDoors_Driver_White");
		InsertIngredient(1,"HatchbackDoors_CoDriver_White");
		InsertIngredient(1,"HatchbackDoors_Driver_GreenRust");
		InsertIngredient(1,"HatchbackDoors_CoDriver_GreenRust");
		InsertIngredient(1,"HatchbackDoors_Driver_BlueRust");
		InsertIngredient(1,"HatchbackDoors_CoDriver_BlueRust");
		InsertIngredient(1,"HatchbackDoors_Driver_WhiteRust");
		InsertIngredient(1,"HatchbackDoors_CoDriver_WhiteRust");
		InsertIngredient(1,"Hatchback_02_Door_1_1");
		InsertIngredient(1,"Hatchback_02_Door_2_1");
		InsertIngredient(1,"Hatchback_02_Door_1_2");
		InsertIngredient(1,"Hatchback_02_Door_2_2");
		InsertIngredient(1,"Hatchback_02_Door_1_1_Black");
		InsertIngredient(1,"Hatchback_02_Door_2_1_Black");
		InsertIngredient(1,"Hatchback_02_Door_1_2_Black");
		InsertIngredient(1,"Hatchback_02_Door_2_2_Black");
		InsertIngredient(1,"Hatchback_02_Door_1_1_Blue");
		InsertIngredient(1,"Hatchback_02_Door_2_1_Blue");
		InsertIngredient(1,"Hatchback_02_Door_1_2_Blue");
		InsertIngredient(1,"Hatchback_02_Door_2_2_Blue");
		InsertIngredient(1,"Hatchback_02_Door_1_1_RedRust");
		InsertIngredient(1,"Hatchback_02_Door_2_1_RedRust");
		InsertIngredient(1,"Hatchback_02_Door_1_2_RedRust");
		InsertIngredient(1,"Hatchback_02_Door_2_2_RedRust");
		InsertIngredient(1,"Hatchback_02_Door_1_1_BlackRust");
		InsertIngredient(1,"Hatchback_02_Door_2_1_BlackRust");
		InsertIngredient(1,"Hatchback_02_Door_1_2_BlackRust");
		InsertIngredient(1,"Hatchback_02_Door_2_2_BlackRust");
		InsertIngredient(1,"Hatchback_02_Door_1_1_BlueRust");
		InsertIngredient(1,"Hatchback_02_Door_2_1_BlueRust");
		InsertIngredient(1,"Hatchback_02_Door_1_2_BlueRust");
		InsertIngredient(1,"Hatchback_02_Door_2_2_BlueRust");
		InsertIngredient(1,"HatchbackHood");
		InsertIngredient(1,"HatchbackHood_Blue");
		InsertIngredient(1,"HatchbackHood_White");
		InsertIngredient(1,"HatchbackHood_GreenRust");
		InsertIngredient(1,"HatchbackHood_BlueRust");
		InsertIngredient(1,"HatchbackHood_WhiteRust");
		InsertIngredient(1,"CivSedanHood");
		InsertIngredient(1,"CivSedanHood_Wine");
		InsertIngredient(1,"CivSedanHood_Black");
		InsertIngredient(1,"CivSedanHood_WhiteRust");
		InsertIngredient(1,"CivSedanHood_WineRust");
		InsertIngredient(1,"CivSedanHood_BlackRust");
		InsertIngredient(1,"Hatchback_02_Hood");
		InsertIngredient(1,"Hatchback_02_Hood_Black");
		InsertIngredient(1,"Hatchback_02_Hood_Blue");
		InsertIngredient(1,"Hatchback_02_Hood_RedRust");
		InsertIngredient(1,"Hatchback_02_Hood_BlackRust");
		InsertIngredient(1,"Hatchback_02_Hood_BlueRust");
		InsertIngredient(1,"HatchbackTrunk");
		InsertIngredient(1,"HatchbackTrunk_Blue");
		InsertIngredient(1,"HatchbackTrunk_White");
		InsertIngredient(1,"HatchbackTrunk_GreenRust");
		InsertIngredient(1,"HatchbackTrunk_BlueRust");
		InsertIngredient(1,"HatchbackTrunk_WhiteRust");
		InsertIngredient(1,"Hatchback_02_Trunk");
		InsertIngredient(1,"Hatchback_02_Trunk_Black");
		InsertIngredient(1,"Hatchback_02_Trunk_Blue");
		InsertIngredient(1,"Hatchback_02_Trunk_RedRust");
		InsertIngredient(1,"Hatchback_02_Trunk_BlackRust");
		InsertIngredient(1,"Hatchback_02_Trunk_BlueRust");
		InsertIngredient(1,"Sedan_02_Trunk");
		InsertIngredient(1,"Sedan_02_Trunk_Red");
		InsertIngredient(1,"Sedan_02_Trunk_Grey");
		InsertIngredient(1,"Sedan_02_Trunk_YellowRust");
		InsertIngredient(1,"Sedan_02_Trunk_RedRust");
		InsertIngredient(1,"Truck_01_Door_1_1");
		InsertIngredient(1,"Truck_01_Door_1_1_Blue");
		InsertIngredient(1,"Truck_01_Door_1_1_BlueRust");
		InsertIngredient(1,"Truck_01_Door_1_1_GreenRust");
		InsertIngredient(1,"Truck_01_Door_1_1_Orange");
		InsertIngredient(1,"Truck_01_Door_2_1");
		InsertIngredient(1,"Truck_01_Door_2_1_Blue");
		InsertIngredient(1,"Truck_01_Door_2_1_BlueRust");
		InsertIngredient(1,"Truck_01_Door_2_1_GreenRust");
		InsertIngredient(1,"Truck_01_Door_2_1_Orange");
		InsertIngredient(1,"Truck_01_Door_2_1_OrangeRust");
		InsertIngredient(1,"Truck_01_Hood");
		InsertIngredient(1,"Truck_01_Hood_Blue");
		InsertIngredient(1,"Truck_01_Hood_BlueRust");
		InsertIngredient(1,"Truck_01_Hood_GreenRust");
		InsertIngredient(1,"Truck_01_Hood_Orange");
		InsertIngredient(1,"Truck_01_Hood_GreenRust");
		InsertIngredient(1,"Truck_01_Hood_OrangeRust");
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1;// -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = true;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
		
		//result1
		AddResult("MetalPlate");//add results here

		m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
		m_ResultSetQuantity[0] = 1;//-1 = do nothing
		m_ResultSetHealth[0] = -1;//-1 = do nothing
		m_ResultInheritsHealth[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
		m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
		m_ResultToInventory[0] = -2;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
		m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
		m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
	}

	override bool CanDo(ItemBase ingredients[], PlayerBase player)//final check for recipe's validity
	{
		return true;
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		Debug.Log("Recipe Do method called","recipes");
	}
};