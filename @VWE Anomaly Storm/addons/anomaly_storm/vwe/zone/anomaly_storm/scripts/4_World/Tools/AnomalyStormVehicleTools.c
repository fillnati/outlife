class AnomalyStormVehicleTools
{
	static int						m_indexes = 0;
	static ref array<string>		m_attachments;
	static ref array<string>		m_animations;
	
	static bool CheckSafePositionInVehicle( PlayerBase player, Transport transport )
	{
		if (!player || !transport)
			return true;
		
		EntityAI	att = null;
		bool		result = true;
		
		if (OffroadHatchback.Cast(transport))
		{
			m_attachments = {"NivaDriverDoors", "NivaCoDriverDoors", "NivaTrunk"};
			m_animations = {"DoorsDriver", "DoorsCoDriver", "DoorsTrunk"};
			m_indexes = 3;
		}
		else if (CivilianSedan.Cast(transport))
		{
			m_attachments = {"CivSedanDriverDoors", "CivSedanCoDriverDoors", "CivSedanCargo1Doors", "CivSedanCargo2Doors"};
			m_animations = {"DoorsDriver", "DoorsCoDriver", "DoorsCargo1", "DoorsCargo2"};
			m_indexes = 4;
		}
		else if (Hatchback_02.Cast(transport))
		{
			m_attachments = {"Hatchback_02_Door_1_1", "Hatchback_02_Door_1_2", "Hatchback_02_Door_2_1", "Hatchback_02_Door_2_2"};
			m_animations = {"DoorsDriver", "DoorsCoDriver", "DoorsCargo1", "DoorsCargo2"};
			m_indexes = 4;
		}
		else if (Sedan_02.Cast(transport))
		{
			m_attachments = {"Sedan_02_Door_1_1", "Sedan_02_Door_2_1", "Sedan_02_Door_1_2", "Sedan_02_Door_2_2"};
			m_animations = {"DoorsDriver", "DoorsCoDriver", "DoorsCargo1", "DoorsCargo2"};
			m_indexes = 4;
		}
		else if (Truck_01_Base.Cast(transport))
		{
			// для Truck_01_Cargo вероятно может потребоваться специальный обработчик.
			m_attachments = {"Truck_01_Door_1_1", "Truck_01_Door_2_1"};
			m_animations = {"DoorsDriver", "DoorsCoDriver"};
			m_indexes = 2;
		}
		else if (Offroad_02.Cast(transport))
		{
			m_attachments = {"Offroad_02_Door_1_1", "Offroad_02_Door_2_1", "Offroad_02_Door_1_2", "Offroad_02_Door_2_2", "Offroad_02_Trunk"};
			m_animations = {"DoorsDriver", "DoorsCoDriver", "DoorsCargo1", "DoorsCargo2", "DoorsTrunk"};
			m_indexes = 5;
		}
		else
			ModCheckSafePositionInVehicle( transport );
		
		if (m_indexes > 0)
		{
			GameInventory inventory = transport.GetInventory();
			if (inventory)
			{
				for (int i = 0; i < m_indexes; i++)
				{
					att = inventory.FindAttachmentByName(m_attachments.Get(i));
					if (att)
					{
						if ( transport.GetAnimationPhase(m_animations.Get(i)) > 0.025 )
						{
							result = false;
							break;
						}
					}
					else
					{
						result = false;
						break;
					}
				}
			}
		}
		else
			result = false;
		
		m_indexes = 0;
		
		if (m_attachments)
			delete m_attachments;
		
		if (m_animations)
			delete m_animations;
		
		return result;
	}
	
	static void ModCheckSafePositionInVehicle( Transport transport )
	{

	}
}