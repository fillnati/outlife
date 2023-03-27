/* modded class PluginRepairing {
    override bool Repair(PlayerBase player, ItemBase repair_kit, ItemBase item, float specialty_weight) {
        CodeLock codelock = CodeLock.Cast(item);

        if (codelock) {
            int healthLevel = codelock.GetHealthLevel();

            if (healthLevel != 0) {
                CalculateHealth(player, repair_kit, item, specialty_weight);
            }
            return true;
        }
        return super.Repair(player, repair_kit, item, specialty_weight);
    }
} */