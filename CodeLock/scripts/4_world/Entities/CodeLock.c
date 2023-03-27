class CodeLock : ItemBase {
    protected ref array<string> arrayGuests;
    protected string m_PassCode, ownerId;
    protected bool m_IsLocked, _flipBool;
    protected float _clHealth;

    protected EffectSound m_Sound;
    protected LockAction m_LockActionPerformed = LockAction.NONE;
    const string SOUND_LOCK_OPEN = "combinationlock_open_SoundSet";
    const string SOUND_LOCK_CLOSE = "combinationlock_close_SoundSet";

    // --- Core functions for the object

    void CodeLock() {
        arrayGuests = new array<string>();
        _flipBool = false;
        
        RegisterNetSyncVariableBool("_flipBool");
        RegisterNetSyncVariableBool("m_IsLocked");
        RegisterNetSyncVariableInt("m_LockActionPerformed", 0, LockAction.COUNT);
        RegisterNetSyncVariableFloat("_clHealth", 0, GetMaxHealth());
    }

    override void EEInit() {
        super.EEInit();
        UpdateVisuals();
    }

    override void OnStoreSave(ParamsWriteContext ctx) {
        auto writeData = new Param1<ref array<string>>(arrayGuests);

        super.OnStoreSave(ctx);
        ctx.Write(m_PassCode);
        ctx.Write(m_IsLocked);
        ctx.Write(ownerId);
        ctx.Write(writeData);
    }

    override bool OnStoreLoad(ParamsReadContext ctx, int version) {
        Param1<ref array<string>> readData;

        if (!super.OnStoreLoad(ctx, version)) {
            return false;
        }
        if (!ctx.Read(m_PassCode)) {
            return false;
        }
        if (!ctx.Read(m_IsLocked)) {
            m_IsLocked = false;
            return false;
        }
        if (!ctx.Read(ownerId)) {
            return false;
        }
        if (!ctx.Read(readData)) {
            return false;
        }
        arrayGuests = readData.param1;

        return true;
    }

    override void AfterStoreLoad() {
        super.AfterStoreLoad();

        if (GetGame().IsServer() && GetGame().IsMultiplayer()) {
            _clHealth = GetHealth();
        }
        Synchronize();
    }

    void Synchronize() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        SetSynchDirty();
        UpdateVisuals();
    }

    override void OnVariablesSynchronized() {
        super.OnVariablesSynchronized();
        GetGame().RPCSingleParam(this, CLRPC.RPC_SERVER_SYNCHLOCK, null, true);
        UpdateVisuals();
        UpdateSound();
    }

    // --- Visual shit

    void UpdateVisuals() {
        if (GetLockState()) {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(HideItem, 0, false);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ShowAttached, 0, false);
        } else {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ShowItem, 0, false);
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(HideAttached, 0, false);
        }
    }

    void UpdateSound() {
        //was locked
        if (m_LockActionPerformed == LockAction.LOCKED) {
            SoundLockClose();
        }

        //was unlocked
        if (m_LockActionPerformed == LockAction.UNLOCKED) {
            SoundLockOpen();
        }
    }

    protected void ShowItem() {
        SetAnimationPhase("Combination_Lock_Item", 0);
        SetAnimationPhase("Lock_Item_1", 0);
        SetAnimationPhase("Lock_Item_2", 0);
    }

    protected void HideItem() {
        SetAnimationPhase("Combination_Lock_Item", 1);
        SetAnimationPhase("Lock_Item_1", 1);
        SetAnimationPhase("Lock_Item_2", 1);
    }

    protected void ShowAttached() {
        SetAnimationPhase("Combination_Lock_Attached", 0);
        SetAnimationPhase("Lock_Attached_1", 0);
        SetAnimationPhase("Lock_Attached_2", 0);
    }

    protected void HideAttached() {
        SetAnimationPhase("Combination_Lock_Attached", 1);
        SetAnimationPhase("Lock_Attached_1", 1);
        SetAnimationPhase("Lock_Attached_2", 1);
    }

    protected void SoundLockOpen() {
        PlaySoundSet(m_Sound, SOUND_LOCK_OPEN, 0, 0);
    }

    protected void SoundLockClose() {
        PlaySoundSet(m_Sound, SOUND_LOCK_CLOSE, 0, 0);
    }

    override void SetActions() {
        super.SetActions();

        AddAction(ActionAttachCodeLockToFence);
        AddAction(ActionAttachCodeLockToTent);
    }

    // ------------------------------------------------------------------------------------------------------------------------------------------------------ \\
    // ------------------------------------------------------------------------------------------------------------------------------------------------------ \\
    // ----------------------------------------------------------------[[ Custom Functions ]]---------------------------------------------------------------- \\
    // ------------------------------------------------------------------------------------------------------------------------------------------------------ \\
    // ------------------------------------------------------------------------------------------------------------------------------------------------------ \\

    // ----------[[ Passcode Handling ]]---------- \\
    // --- Getters // Setters

    void SetPasscode(string passcode) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        
        m_PassCode = passcode;
    }

    void SetLockedState(bool state) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        
        m_IsLocked = state;
    }

    string GetPasscode() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return ":-)"; }
        
        return m_PassCode;
    }

    bool IsLocked(string ui_Passcode) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return true; }
        
        if (m_PassCode != ui_Passcode) {
            return true;
        }
        return false;
    }

    bool GetLockState() {
        return m_IsLocked;
    }

    // --- Core

    void LockServer(ItemBase parent, string passcode) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        
        InventoryLocation inventorylocation = new InventoryLocation;
        GetInventory().GetCurrentInventoryLocation(inventorylocation);
        parent.GetInventory().SetSlotLock(inventorylocation.GetSlot(), true);

        m_LockActionPerformed = LockAction.LOCKED;
        m_PassCode = passcode;
        m_IsLocked = true;
        _flipBool = !_flipBool;

        SetTakeable(false);
        Synchronize();
    }

    void UnlockServer(notnull EntityAI player, EntityAI parent) {
        NewUnlockServer(player, parent);
    }

    void NewUnlockServer(EntityAI player, EntityAI parent) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }
        InventoryLocation inventorylocation = new InventoryLocation();

        GetInventory().GetCurrentInventoryLocation(inventorylocation);
        parent.GetInventory().SetSlotLock(inventorylocation.GetSlot(), false);

        if (player)
        {
            player.ServerDropEntity( this );
            SetPosition(player.GetPosition());
        }
        else
        {
            parent.GetInventory().DropEntity(InventoryMode.SERVER, parent, this);
            SetPosition(parent.GetPosition());
        }
        PlaceOnSurface();

        m_LockActionPerformed = LockAction.UNLOCKED;
        m_PassCode = string.Empty;
        m_IsLocked = false;
        ownerId = string.Empty;
        arrayGuests = new array<string>();
        _flipBool = !_flipBool;

        SetTakeable(true);
        Synchronize();
    }

    // ----------[[ Owner / Guest Handling ]]---------- \\
    // --- Getters // Setters

    void ServerSetOwner(string id) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if (ownerId == string.Empty) {
            ownerId = id;
            _flipBool = !_flipBool;

            SetSynchDirty();
        } else {
            ServerAddGuest(id);
        }
    }

    void ServerAddGuest(string id) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        if (!IsGuest(id)) {
            _flipBool = !_flipBool;

            arrayGuests.Insert(id);
            SetSynchDirty();
        }
    }

    ref array<string> GetGuests() {
        return arrayGuests;
    }

    string GetOwner() {
        return ownerId;
    }

    bool IsOwner(string id) {
        if (id == ownerId) {
            return true;
        }
        return false;
    }

    bool IsGuest(string id) {
        if (arrayGuests.Find(id) > -1) {
            return true;
        }
        return false;
    }

    bool HasNoOwner() {
        if (ownerId == string.Empty) {
            return true;
        }
        return false;
    }

    // --- Core

    void ServerClearGuests() {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        arrayGuests = new array<string>();
        _flipBool = !_flipBool;

        SetSynchDirty();
    }

    void SynchLock(string owner, ref array<string> guests) {
        if (GetGame().IsServer() || !GetGame().IsClient()) { return; }

        ownerId = owner;
        arrayGuests = guests;
    }

    // --- Object Health Synchronization

    void SetSynchronizedHealth(float health) {
        if (!GetGame().IsServer() || !GetGame().IsMultiplayer()) { return; }

        _clHealth = health;
        SetSynchDirty();
    }

    float GetSynchronizedHealth() {
        return _clHealth;
    }
}