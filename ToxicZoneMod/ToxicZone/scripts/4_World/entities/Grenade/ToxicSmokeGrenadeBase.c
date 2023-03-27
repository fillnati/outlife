class ToxicSmokeBase extends M18SmokeGrenade_ColorBase
{
	private bool End = false;
	// When smoke starts
	override void OnWorkStart()
	{
		super.OnWorkStart();
		thread CheckPlayerNearby();
	}

	override void OnWorkStop()
	{
		super.OnWorkStop();
		End = true;
	}

	void CheckPlayerNearby()
	{
		Sleep(30000);
		while(End!=true)
		{
			array<Object> proche_objects = new array<Object>;
			PlayerBase FindPlayer;

			GetGame().GetObjectsAtPosition3D(this.GetPosition(), 8, proche_objects, NULL);
			if (proche_objects.Count() < 1)
			{
				return;
			}
			FindPlayer = NULL;

			for (int i = 0; i < proche_objects.Count(); ++i)
			{
				string tempObjId = proche_objects.Get(i).ToString();
				tempObjId.ToLower();
				if (tempObjId.Contains("static")) continue;
				if (proche_objects.Get(i).IsWell() || proche_objects.Get(i).IsBush()) continue;
				if (proche_objects.Get(i).IsRock() || proche_objects.Get(i).IsTree()) continue;
				if (proche_objects.Get(i).IsBuilding()) continue;
				if (proche_objects.Get(i).IsWoodBase() ) continue;
				if (proche_objects.Get(i).IsKindOf("SurvivorBase")){
					FindPlayer=PlayerBase.Cast(proche_objects.Get(i));
					if(FindPlayer && !FindPlayer.IsToxicSick){
						FindPlayer.GasMaskCheck();
					}
				}
			}
			if (!FindPlayer)
			{
				return;
			}
			Sleep(15000);
		}
	}
}
