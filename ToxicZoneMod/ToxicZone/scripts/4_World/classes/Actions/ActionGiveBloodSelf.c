modded class ActionGiveBloodSelf: ActionContinuousBase
{
	override void OnEndServer(ActionData action_data)
	{
		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		if(player)
		{
			if(player.IsInside.TZStatut)
			{
				player.GiveShock(-100);
				float currenthealth = player.GetHealth("GlobalHealth", "Blood");
				player.SetHealth("GlobalHealth", "Blood" ,  currenthealth - 1000 );
			}
			else
			{
				super.OnEndServer(action_data);
			}
		}
	}
};
