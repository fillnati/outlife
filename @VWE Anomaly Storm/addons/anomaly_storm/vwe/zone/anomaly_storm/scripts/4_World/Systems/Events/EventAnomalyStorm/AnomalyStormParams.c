class AnomalyStormParams : Class
{
	protected float								m_damageFactor;
	protected string							m_logicClientName;	
	protected bool								m_isShowNotification;
	protected bool								m_isPlaySoundAlarm;
	
	void AnomalyStormParams()
	{
		m_damageFactor = 0.5;
		m_logicClientName = "AnomalyStormLogicClient";
		m_isShowNotification = false;
		m_isPlaySoundAlarm = false;
	}
	
	float GetDamageFactor() { return Clamp(m_damageFactor, 0, 0.999999); }
	void SetDamageFactor(float v) { m_damageFactor = Clamp(v, 0, 0.999999); }	
	string GetLogicClientName() { return m_logicClientName; }	
	bool IsShowNotification() { return m_isShowNotification; }
	bool IsPlaySoundAlarm() { return m_isPlaySoundAlarm; }
	
	protected int FormatTime(int t, int format)
	{
		if (format == TimeFormat.M)
			return t;
		else if (format == TimeFormat.S)
			return t * 60;
		return t * 60 * 1000;
	}
	
	protected float Clamp(float v, float min = 0, float max = 1)
	{
		if (v < min)
			return min;
		else if (v > max)
			return max;
		return v;
	}
};
