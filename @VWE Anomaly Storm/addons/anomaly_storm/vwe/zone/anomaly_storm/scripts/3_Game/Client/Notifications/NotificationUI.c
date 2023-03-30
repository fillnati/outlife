modded class NotificationUI
{
	void NotificationUI()
	{
		NotificationSystemExtension ntfSys = NotificationSystemExtension.GetInstance();
		if (ntfSys)
		{
			ntfSys.m_OnNotificationUpdated.Insert( UpdateNotification );
		}
	}
	
	void ~NotificationUI()
	{
		NotificationSystemExtension ntfSys = NotificationSystemExtension.GetInstance();
		if (ntfSys)
		{
			ntfSys.m_OnNotificationUpdated.Remove( UpdateNotification );
		}
	}
	
	void UpdateNotification( NotificationRuntimeData data )
	{
		if( m_Notifications.Contains( data ) )
		{
			Widget notification		= m_Notifications.Get( data );
			ImageWidget icon		= ImageWidget.Cast( notification.FindAnyWidget( "Image" ) );
			RichTextWidget title	= RichTextWidget.Cast( notification.FindAnyWidget( "Title" ) );
			
			if( data.GetIcon() != "" )
				icon.LoadImageFile( 0, data.GetIcon() );
			
			title.SetText( data.GetTitleText() );
					
			Widget bottom_spacer	= notification.FindAnyWidget( "BottomSpacer" );
			RichTextWidget detail	= RichTextWidget.Cast( notification.FindAnyWidget( "Detail" ) );
			bottom_spacer.Show(true);
			detail.SetText( data.GetDetailText() );
			detail.Update();
			bottom_spacer.Update();
			notification.Update();
			
			UpdateTargetHeight();
		}
	}
}