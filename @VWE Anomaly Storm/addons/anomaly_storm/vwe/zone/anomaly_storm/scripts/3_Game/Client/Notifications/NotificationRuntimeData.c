modded class NotificationRuntimeData
{
	void SetIcon(string icon)
	{
		m_StaticData.m_Icon = icon;
	}
	
	void SetTitleText(string text)
	{
		m_StaticData.m_TitleText = text;
	}
	
	void SetDetailText(string text)
	{
		m_DetailText = text;
	}
}