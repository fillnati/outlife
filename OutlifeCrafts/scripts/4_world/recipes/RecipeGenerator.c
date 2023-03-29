//Made by Pechyvo
modded class PluginRecipesManager
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        //Vanilla Crafts
        RegisterRecipe(new CraftBarrel );
        RegisterRecipe(new CraftSeaChest );
        RegisterRecipe(new CraftMetalSheet );
        
        //AWS Craft
        RegisterRecipe(new MountRMROnNFATACRB13);
        RegisterRecipe(new AddACOGMountForM16A2);
    }
};