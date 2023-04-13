//Made by Pechyvo
modded class PluginRecipesManager
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        //Vanilla Crafts
        RegisterRecipe(new CraftNails );
        RegisterRecipe(new DeCraftBarrel );
        RegisterRecipe(new CraftSeaChest );
        RegisterRecipe(new CraftMetalSheet );
        RegisterRecipe(new CraftGhillieBushragFromCamonetMossy );
        RegisterRecipe(new CraftGhillieTopFromCamonetMossy );
        RegisterRecipe(new CraftGhillieAttachmentFromCamonetMossy );
        RegisterRecipe(new CraftGhillieHoodFromCamonetMossy );
        RegisterRecipe(new CraftGhillieSuitFromCamonetMossy );
        RegisterRecipe(new CraftGhillieBushragFromCamonetWoodland );
        RegisterRecipe(new CraftGhillieTopFromCamonetWoodland );
        RegisterRecipe(new CraftGhillieAttachmentFromCamonetWoodland );
        RegisterRecipe(new CraftGhillieHoodFromCamonetWoodland );
        RegisterRecipe(new CraftGhillieSuitFromCamonetWoodland );
        
        //AWS Craft
        RegisterRecipe(new MountRMROnNFATACRB13);
        RegisterRecipe(new AddACOGMountForM16A2);

        //SSM_CamoNetWrap
        RegisterRecipe(new SSM_CraftCamonetWrap);
    }
};