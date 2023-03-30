class NotificationSystemExtension
{
	ref ScriptInvoker										m_OnNotificationUpdated = new ScriptInvoker;
	protected ref NotificationRuntimeData					m_editableNotification = null;
	
	protected static ref NotificationSystemExtension		m_instance;
	
	static NotificationSystemExtension GetInstance()
	{
		if (!m_instance)
			m_instance = new NotificationSystemExtension();
		return m_instance;
	}
	
	void ShowNotificationEditable( string title_text, string detail_text = "", string icon = "" )
	{
		if (m_editableNotification) return;
		
		float time = GetGame().GetTickTime();
		ref NotificationData temp_data = new NotificationData( icon, title_text );
		m_editableNotification = new NotificationRuntimeData(time, temp_data, detail_text);
		if (NotificationSystem.GetInstance())
			NotificationSystem.GetInstance().m_OnNotificationAdded.Invoke( m_editableNotification );
	}
	
	void UpdateNotificationEditable( string title_text, string detail_text, string icon = "" )
	{
		if (m_editableNotification)
		{
			m_editableNotification.SetTitleText(title_text);
			m_editableNotification.SetDetailText(detail_text);
			if (icon != "")
				m_editableNotification.SetIcon(icon);
			
			m_OnNotificationUpdated.Invoke( m_editableNotification );
		}
	}
	
	void RemoveNotificationEditable()
	{
		if (m_editableNotification)
		{
			if (NotificationSystem.GetInstance())
				NotificationSystem.GetInstance().m_OnNotificationRemoved.Invoke( m_editableNotification );
			m_editableNotification = null;
		}
	}
}