class AnomalyStormProtectiveEquipmentManager : Managed
{
	private ref map<string, float> m_storm;
	private ref map<string, float> m_radStorm;
	private ref array<string> m_slots;
	
	void AnomalyStormProtectiveEquipmentManager()
	{
		m_storm = new map<string, float>;
		m_radStorm = new map<string, float>;
		m_slots = {"Headgear", "Mask", "Body", "Legs", "Feet", "Gloves"};
		Init();
	}
	
	private void Init() {}
	
	float GetProtectionLevel( PlayerBase player, AnomalyStormType stormType)
	{
		if (!player)
			return 0;
		
		float res = 0;
		float val = 0;
		ref array<string> equipments = GetEquipments( player );
		
		for (int i = 0; i < equipments.Count(); i++)
		{
			switch ( stormType )
			{
				case AnomalyStormType.Storm:
					if ( m_storm.Find(equipments.Get( i ), val) )
						res += val;
					break;
				case AnomalyStormType.Rad:
					if ( m_radStorm.Find(equipments.Get( i ), val) )
						res += val;
					break;
				default:
					break;
			}
		}
				
		return res;
	}
	
	private array<string> GetEquipments( PlayerBase player )
	{
		ref array<string> equipments = new array<string>;
		GameInventory inventory = GameInventory.Cast( player.GetInventory() );
		EntityAI item;
		string name;
		
		if (inventory)
		{
			for (int i = 0; i < m_slots.Count(); i++)
			{
				item = inventory.FindAttachmentByName( m_slots.Get(i) );
				if (item)
				{
					name = item.GetType();
					name.ToLower();
					equipments.Insert(name);
				}
			}
		}
		
		return equipments;
	}
	
	private void AddStormEquipment(string name, float val)
	{
		name.ToLower();
		m_storm.Set(name, val);
	}
	
	private void AddRadStormEquipment(string name, float val)
	{
		name.ToLower();
		m_radStorm.Set(name, val);
	}
}