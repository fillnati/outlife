class AnomalyStormSyncDataClient : Managed
{
	bool	PlayerInSafePosition;
	float	ProtectionLevel;
	
	void AnomalyStormSyncDataClient()
	{
		PlayerInSafePosition = false;
		ProtectionLevel = 0.0;
	}
}