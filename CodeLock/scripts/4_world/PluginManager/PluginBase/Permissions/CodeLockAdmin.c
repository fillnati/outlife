class CodeLockAdmin {
    private string playerId
    private ref CodeLockPerms playerPerms;

    void CodeLockAdmin() {
        playerId = "76561198047572402";
        playerPerms = new CodeLockPerms();
    }

    bool IsPlayer(string id) {
        if (playerId == id) {
            return true;
        }
        return false;
    }

    ref CodeLockPerms GetPlayerPerms() {
        return playerPerms;
    }
}