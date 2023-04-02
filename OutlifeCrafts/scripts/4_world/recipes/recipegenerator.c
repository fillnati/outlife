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
        RegisterRecipe(new CraftGhillieBushragFromCamonet );
        RegisterRecipe(new CraftGhillieTopFromCamonet );
        RegisterRecipe(new CraftGhillieAttachmentFromCamonet );
        RegisterRecipe(new CraftGhillieHoodFromCamonet );
        RegisterRecipe(new CraftGhillieSuitFromCamonet );
        
        //AWS Craft
        RegisterRecipe(new MountRMROnNFATACRB13);
        RegisterRecipe(new AddACOGMountForM16A2);
    }
};