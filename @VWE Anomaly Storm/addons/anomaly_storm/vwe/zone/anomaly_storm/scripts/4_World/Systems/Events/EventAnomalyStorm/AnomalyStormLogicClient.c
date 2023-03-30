class AnomalyStormLogicClient : AnomalyStormLogic
{
	const string 						ANOMALYSTORM_ALARM_SOUND_SET				= "Anomalystorm_Alarm_01_SoundSet";
	const string 						RADSTORM_ALARM_SOUND_SET					= "Radstorm_Alarm_01_SoundSet";
	const string 						ANOMALYSTORM_BACKGROUND_SOUND_SET			= "Radstorm_Background_SoundSet";
	const string 						RADSTORM_BACKGROUND_SOUND_SET				= "Radstorm_Background_SoundSet";
	
	const string						ANOMALYSTORM_MSG_STORM_WARNING_SOUND_SET	= "Anomalystorm_Msg_AnomalyStormWarning_01_SoundSet";
	const string						RADSTORM_MSG_STORM_WARNING_SOUND_SET		= "Anomalystorm_Msg_RadStormWarning_01_SoundSet";	
	const string						ANOMALYSTORM_MSG_STORM_START_SOUND_SET		= "Anomalystorm_Msg_AnomalyStormStarted_01_SoundSet";
	const string						ANOMALYSTORM_MSG_STORM_END_SOUND_SET		= "Anomalystorm_Msg_AnomalyStormEnd_01_SoundSet";
	const string						RADSTORM_MSG_STORM_START_SOUND_SET			= "Anomalystorm_Msg_RadStormStarted_01_SoundSet";
	const string						RADSTORM_MSG_STORM_END_SOUND_SET			= "Anomalystorm_Msg_RadStormEnd_01_SoundSet";
	
	const string						ANOMALY_STORM_ICON							= "vwe/zone/anomaly_storm/gui/icons/icon_storm.edds";
	const string						RAD_STORM_ICON								= "vwe/zone/anomaly_storm/gui/icons/icon_rad_02.edds";
	
	const string						ANOMALY_STORM_NAME							= "#anomaly_storm_storm_name";
	const string						RAD_STORM_NAME								= "#anomaly_storm_rad_storm_name";
	const string						PSY_STORM_NAME								= "#anomaly_storm_psy_storm_name";
	const string						MSG_FIND_SAFE_POSITION						= "#anomaly_storm_msg_find_safe_position";
	const string						MSG_DANGER_VALUE							= "#anomaly_storm_msg_danger_value";
	const string						MSG_RAD_DANGER_VALUE						= "#anomaly_storm_msg_rad_danger_value";
	const string						MSG_THIS_SAFE_POSITION						= "#anomaly_storm_msg_this_safe_position";
	const string						MSG_STORM_END								= "#anomaly_storm_msg_storm_end";
	const string						MSG_STORM_END_2								= "#anomaly_storm_msg_storm_end_2";
	const string						MSG_RESPAWN									= "#anomaly_storm_msg_respawn";
	
	const float							CAMERA_SHAKE_SLICE							= 0.1;
	
	protected bool						m_jip;
	protected ref Timer					m_cameraShakeTimer;
	protected float						m_cameraShakeTimerTimeout;
	protected float 					m_cameraShakeFactor;
	protected float 					m_soundBackgroundVolume;
	protected int						m_soundBackgroundFadeFactor;
	protected AbstractWave 				m_soundBackground;
	protected PhxInteractionLayers		m_safePositionCollisionLayerMask;
	protected ref Timer					m_updateTimer;
	protected int						m_updateTimerTimeout;
	protected bool						m_isNotification;
	protected ref CameraShakeLoop 		m_cameraShake;
	protected int 						m_defaultWorldLightingID;
	protected int 						m_currentWorldLightingID;
	
	protected ref AnomalyStormProtectiveEquipmentManager	m_protectiveEquipmentManager;
	
	void AnomalyStormLogicClient()
	{
		m_jip = false;
		m_cameraShakeTimer = new Timer(CALL_CATEGORY_SYSTEM);
		m_cameraShakeTimerTimeout = 0.05; //s
		m_cameraShakeFactor = 0;
		m_soundBackgroundVolume = 0;
		m_soundBackgroundFadeFactor = 0;
		m_safePositionCollisionLayerMask = PhxInteractionLayers.BUILDING; // PhxInteractionLayers.ITEM_LARGE|PhxInteractionLayers.VEHICLE
		m_updateTimer = new Timer(CALL_CATEGORY_SYSTEM);
		m_updateTimerTimeout = 1; // s
		m_isNotification = false;
		m_cameraShake = null;
		m_defaultWorldLightingID = 0;
		m_currentWorldLightingID = 0;
		m_protectiveEquipmentManager = new AnomalyStormProtectiveEquipmentManager();
	}
	
	void ~AnomalyStormLogicClient()
	{
		if ( GetGame() )
		{
			StopSoundBackground();			
			RemoveNotification();
			DestroyCameraShake();
		}
	}
	
	override void StormWarning()
	{
		BroadcastSoundMessageWarning();
	}
	
	override void BeforeStormPhaseStart()
	{
		if (!m_jip)
			m_jip = true;
		
		BroadcastSoundMessage();
		BroadcastSoundAlarm();
		InitStorm();
	}
	
	override void OnStormPhaseStart()
	{
		float phaseValue = m_plugin.GetStormPhaseValue();
		m_cameraShakeFactor = phaseValue;
		m_soundBackgroundVolume = phaseValue;
		m_soundBackgroundFadeFactor = 1;
		
		if (m_jip)
		{
			UpdateSoundBackground();
			CheckPlayerRespawn();
		}
		else
		{
			InitStorm();
			SetSoundBackgroundVolume( m_soundBackgroundVolume );
			m_jip = true;
		}
	}
	
	override void AfterStormPhaseStart()
	{
		m_cameraShakeFactor = 1;
		m_soundBackgroundVolume = 1;
		m_soundBackgroundFadeFactor = 1;
		
		if (m_jip)
		{
			UpdateSoundBackground();
			CheckPlayerRespawn();
		}
		else
		{
			InitStorm();
			SetSoundBackgroundVolume( m_soundBackgroundVolume );
			m_jip = true;
		}
	}
	
	override void BeforeStormPhaseRun()
	{
		ActiveStormPhaseLoop();
	}
	
	override void OnStormPhaseRun()
	{
		ActiveStormPhaseLoop();
	}
	
	override void AfterStormPhaseRun()
	{
		ActiveStormPhaseLoop();
	}
	
	override void BeforeStormPhaseEnd()
	{
		ActiveStormPhaseLoop();
	}
	
	override void OnStormPhaseEnd()
	{
		float phaseValue = m_plugin.GetStormPhaseValue();
		m_cameraShakeFactor = 1 - phaseValue;
		m_soundBackgroundVolume = 1 - phaseValue;
		m_soundBackgroundFadeFactor = -1;
		
		if (m_jip)
		{
			UpdateSoundBackground();
			CheckPlayerRespawn();
		}
		else
		{
			InitStorm();
			SetSoundBackgroundVolume( m_soundBackgroundVolume );
			m_jip = true;
		}
	}
	
	override void AfterStormPhaseEnd()
	{
		if (!m_jip) return;
		
		if ( IsSafePosition() )
			UpdateNotification( GetStormName(), MSG_STORM_END );
		else
			UpdateNotification( GetStormName(), MSG_STORM_END_2 );
		
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.RemoveNotification, 5000.0, false );
		
		BroadcastSoundMessage();
		
		ResetStorm();
	}
	
	protected void InitStorm()
	{
		if (m_plugin.GetStormType() == AnomalyStormType.Rad)
		{
			SetStormWorldLighting();
		}		
		
		PlaySoundBackground();
		
		if ( m_plugin.IsShowNotification() )
		{
			string stormIcon = "";
			switch ( m_plugin.GetStormType() )
			{
				case AnomalyStormType.Storm:
					stormIcon = ANOMALY_STORM_ICON;
					break;
				case AnomalyStormType.Rad:
					stormIcon = RAD_STORM_ICON;
					break;
			}
			
			ShowNotification( GetStormName(), MSG_FIND_SAFE_POSITION, stormIcon );
		}
		
		if (!m_updateTimer.IsRunning())
			m_updateTimer.Run( m_updateTimerTimeout, this, "Update", null, true);
				
		if (!m_cameraShakeTimer.IsRunning())
			m_cameraShakeTimer.Run( m_cameraShakeTimerTimeout, this, "SpawnCameraShake", null, true);
	}
	
	protected void ActiveStormPhaseLoop()
	{
		if (m_jip)
		{
			CheckPlayerRespawn();
		}
		else
		{
			m_cameraShakeFactor = 1;
			m_soundBackgroundVolume = 1;
			m_soundBackgroundFadeFactor = 1;
			InitStorm();
			SetSoundBackgroundVolume( m_soundBackgroundVolume );
			m_jip = true;
		}
	}
	
	protected void ResetStorm()
	{
		if ( m_plugin.GetStormType() == AnomalyStormType.Rad )
			SetDefaultWorldLighting();
				
		m_cameraShakeTimer.Stop();
		if (m_cameraShakeTimer.IsRunning())
			Print("[AnomalyStormLogicClient::ResetStorm][error] не удалось остановить работу m_cameraShakeTimer");
		
		m_updateTimer.Stop();
		if (m_updateTimer.IsRunning())
			Print("[AnomalyStormLogicClient::ResetStorm][error] не удалось остановить работу m_updateTimer");
		
		StopSoundBackground();
		m_cameraShakeFactor = 0;
		m_soundBackgroundVolume = 0;
		m_soundBackgroundFadeFactor = 0;
		
		DestroyCameraShake();
	}
	
	protected void CheckPlayerRespawn()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		
		if ( player && player.IsAlive() )
		{
			AnomalyStormType type = m_plugin.GetStormType();
			WorldLightingID wlID;
			if ( type == AnomalyStormType.Rad )
				wlID = WorldLightingID.RadStorm;
			else
				return;
				
			if ( GetGame().GetMission().GetWorldLighting().GetGlobalLightingID() != (int)wlID )
				SetStormWorldLighting();
		}
	}
	
	protected void SetStormWorldLighting()
	{
		m_defaultWorldLightingID = GetGame().GetMission().GetWorldLighting().GetGlobalLightingID();
		
		switch ( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Rad:
				m_currentWorldLightingID = (int)WorldLightingID.RadStorm;
				break;
		}
		
		GetGame().GetMission().GetWorldLighting().SetGlobalLighting( m_currentWorldLightingID );
	}
	
	protected void SetDefaultWorldLighting()
	{
		m_currentWorldLightingID = m_defaultWorldLightingID;
		GetGame().GetMission().GetWorldLighting().SetGlobalLighting( m_defaultWorldLightingID );
	}
	
	protected void Update()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		string msgDangerValue = "";
		string stormIcon = "";
		switch ( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Storm:
				msgDangerValue = MSG_DANGER_VALUE;
				stormIcon = ANOMALY_STORM_ICON;
				break;
			case AnomalyStormType.Rad:
				msgDangerValue = MSG_RAD_DANGER_VALUE;
				stormIcon = RAD_STORM_ICON;
				break;
		}	

		if (player)
		{
			if (player.IsAlive())
			{
				CheckSafePosition( player );
				CheckProtectiveEquipment( player );
				player.AnomalyStormSendDataClient();
				
				if ( !m_plugin.IsShowNotification() )
				{
					if (m_isNotification)
						RemoveNotification();
					
					return;
				}			
				
				if ( player.IsPlayerInSafePosition() )
					UpdateNotification( GetStormName(), MSG_THIS_SAFE_POSITION );
				else
				{
					if ( GetDamageFactor() <= 0 )
						UpdateNotification( GetStormName(), MSG_FIND_SAFE_POSITION );
					else
						UpdateNotification( GetStormName(), msgDangerValue );
				}
			}
			else
			{
				if (m_isNotification)
					UpdateNotification( GetStormName(), MSG_RESPAWN );
				else
					ShowNotification( GetStormName(), MSG_RESPAWN, stormIcon );
			}
		}
		else
		{
			//RemoveNotification(); // под большим вопросом, стоит ли, или просто изменить текст сообщения, или вообще удалить этот вызов. 
		}
	}
	
	protected void CheckSafePosition( PlayerBase player )
	{
		float hitFraction;
		vector hitPosition, hitNormal;
		Object hitObject;
		bool isSafePosition = true;
		
		if (player.IsInVehicle() && (PhxInteractionLayers.VEHICLE & m_safePositionCollisionLayerMask))
		{
			HumanCommandVehicle vehicleCommand = player.GetCommand_Vehicle();
			if( vehicleCommand )
			{
				Transport transport = vehicleCommand.GetTransport();
				if (transport)
				{
					isSafePosition = AnomalyStormVehicleTools.CheckSafePositionInVehicle( player, transport );
				}
			}
			
			player.PlayerInSafePosition( isSafePosition );
			return;
		}
		
		vector from = player.GetPosition() + "0 0.7 0";
		
		vector toArray[5];
		toArray[0] = from + "0 25 0";		// t
		toArray[1] = from + "0 25 25";		// f
		toArray[2] = from + "0 25 -25";		// b
		toArray[3] = from + "-25 25 0";		// l
		toArray[4] = from + "25 25 0";		// r
		
		// после обновления от 15.01.2020, функции *CastBullet стали возвращать не корректные результаты.
		// возвращаемое функцией булево значение корректно, всегда фиксируется контакт с поверхностью, но, возвращаемый результат переменной hitObject всегда NULL
		// как вариант, данная версия алгоритма вполне достаточна, если в дальнейшем не возникнет необходимость фиксировать идентичность объекта всеми лучами.
		for (int i = 0; i < 5; i++)
		{
			if ( !DayZPhysics.RayCastBullet(from, toArray[i], m_safePositionCollisionLayerMask, null, hitObject, hitPosition, hitNormal, hitFraction) )
			{
				isSafePosition = false;
				break;
			}
		}
		
		if (isSafePosition)
			isSafePosition = ModCheckSafePosition( player );
		
		player.PlayerInSafePosition( isSafePosition );
	}
	
	protected bool ModCheckSafePosition( PlayerBase player )
	{
		return true;
	}
	
	protected bool IsSafePosition()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		return player.IsPlayerInSafePosition();
	}
	
	protected void CheckProtectiveEquipment( PlayerBase player )
	{
		float v = m_protectiveEquipmentManager.GetProtectionLevel( player, m_plugin.GetStormType() );
		player.SetAnomalyStormProtectionLevel( v );
	}
	
	protected float GetProtectionLevel()
	{
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		return player.GetAnomalyStormProtectionLevel();
	}
	
	protected void DestroyCameraShake()
	{
		if (m_cameraShake)
		{
			delete m_cameraShake;
		
			// странное недоразумение, если я правильно осмыслил код камер, то при смене камеры происходит передача параметров предыдущей камеры актуальной, но что то идёт не так.
			// после вызова трясок камерой, если во время данного события начать переключаться между камерами, то после отработки функционала, ориентация камер становится не корректной
			// корректна только та камера на которой завершил работу функционал тряски камеры.
			// далее фиксим сами.
			DayZPlayerImplement player = DayZPlayerImplement.Cast(GetGame().GetPlayer());
			if (player)
				player.GetAimingModel().SetCamShakeValues(0, 0);
		}
	}
	
	protected void SpawnCameraShake()
	{
		if (!GetGame().GetPlayer()) return;
		
		DayZPlayerCameraBase camera = DayZPlayerCameraBase.Cast( GetGame().GetPlayer().GetCurrentCamera() );
		if (!camera) return;
			
		if (!m_cameraShake)
			m_cameraShake = new CameraShakeLoop( 0, 20, 1, 0); //последний параметр не учитывается, нужен для корректного наследования
			
		if (!camera.IsCameraShake())
			camera.SetCameraShake(m_cameraShake);
			
		if (camera.IsCameraShakeLoop())
		{
			float slice = Clamp( CAMERA_SHAKE_SLICE, 0, 0.999999);
			float factor = Clamp(m_cameraShakeFactor - slice) / (1 - slice);
			m_cameraShake.SetStregthFactor(factor  * 0.05);
		}
	}
	
	protected void BroadcastSoundMessageWarning()
	{
		string soundSet = "";
		switch ( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Storm:
				soundSet = ANOMALYSTORM_MSG_STORM_WARNING_SOUND_SET;
				break;
			case AnomalyStormType.Rad:
				soundSet = RADSTORM_MSG_STORM_WARNING_SOUND_SET;
				break;
		}
		
		if ( soundSet == "" )
		{
			Print("[AnomalyStormLogicClient::BroadcastSoundMessageWarning][error] определён не коректный конфиг класс SoundSet для переменной soundSet");
			return;
		}
		
		m_plugin.BroadcastToZoneRadios(soundSet, 0, 0);
	}
	
	protected void BroadcastSoundMessage()
	{
		string soundSet = "";
		AnomalyStormPhase stormPhase = m_plugin.GetStormPhase();
		
		switch ( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Storm:
				if (stormPhase == AnomalyStormPhase.BeforeStart)
					soundSet = ANOMALYSTORM_MSG_STORM_START_SOUND_SET;
				else if (stormPhase == AnomalyStormPhase.AfterEnd)
					soundSet = ANOMALYSTORM_MSG_STORM_END_SOUND_SET;
				break;
			case AnomalyStormType.Rad:
				if (stormPhase == AnomalyStormPhase.BeforeStart)
					soundSet = RADSTORM_MSG_STORM_START_SOUND_SET;
				else if (stormPhase == AnomalyStormPhase.AfterEnd)
					soundSet = RADSTORM_MSG_STORM_END_SOUND_SET;
				break;
		}
		
		if ( soundSet == "" )
		{
			Print("[AnomalyStormLogicClient::BroadcastSoundMessage][error] определён не коректный конфиг класс SoundSet для переменной soundSet");
			return;
		}
		
		m_plugin.BroadcastToZoneRadios(soundSet, 0, 0);
	}
	
	protected void BroadcastSoundAlarm()
	{
		if (!m_plugin.IsPlaySoundAlarm())
			return;
		
		string soundSet = "";
		switch ( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Storm:
				soundSet = ANOMALYSTORM_ALARM_SOUND_SET;
				break;
			case AnomalyStormType.Rad:
				soundSet = RADSTORM_ALARM_SOUND_SET;
				break;
		}
		
		if ( soundSet == "" )
		{
			Print("[AnomalyStormLogicClient::BroadcastSoundAlarm][error] определён не коректный конфиг класс SoundSet для переменной soundSet");
			return;
		}
		
		m_plugin.BroadcastToPASReceivers(soundSet, 0, 0);
	}

	protected void PlaySoundBackground(float volume = 0)
	{
		if ( m_soundBackground )
			return;
		
		string soundSet = "";
		switch ( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Storm:
				soundSet = ANOMALYSTORM_BACKGROUND_SOUND_SET;
				break;
			case AnomalyStormType.Rad:
				soundSet = RADSTORM_BACKGROUND_SOUND_SET;
				break;
		}
		
		if ( soundSet == "" )
		{
			Print("[AnomalyStormLogicClient::PlaySoundBackground][error] определён не коректный конфиг класс SoundSet для переменной soundSet");
			return;
		}
		
		ref SoundParams soundParams			= new SoundParams( soundSet );
		ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
		ref SoundObject soundObject			= soundBuilder.BuildSoundObject();
		soundObject.SetKind( WaveKind.WAVEEFFECTEX ); // WAVEEFFECT, WAVEEFFECTEX, WAVEATTALWAYS
		m_soundBackground = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
		m_soundBackground.Loop( true );		
		m_soundBackground.SetVolume( volume );
		m_soundBackground.Play();
	}
	
	protected void StopSoundBackground()
	{
		if ( m_soundBackground )
		{
			m_soundBackground.Stop();
			m_soundBackground = null;
		}
	}
	
	protected void SetSoundBackgroundVolume(float volume)
	{
		if ( m_soundBackground )
			m_soundBackground.SetVolume( Clamp( volume ) );
	}
	
	protected void UpdateSoundBackground()
	{
		if ( m_soundBackground )
		{
			float volume = Clamp( m_soundBackgroundVolume );
			
			if (m_soundBackgroundFadeFactor > 0)
				m_soundBackground.SetFadeInFactor( volume );
			else if (m_soundBackgroundFadeFactor < 0)
				m_soundBackground.SetFadeOutFactor( volume );
			
			m_soundBackground.SetVolume( volume );
		}
	}
	
	protected void ShowNotification(string title, string detail, string icon = "")
	{
		if (!m_isNotification)
		{
			NotificationSystemExtension.GetInstance().ShowNotificationEditable( title, detail, icon );
			m_isNotification = true;
		}
	}
	
	protected void UpdateNotification(string title, string detail, string icon = "")
	{
		if (m_isNotification)
		{
			NotificationSystemExtension.GetInstance().UpdateNotificationEditable( title, detail, icon );
		}
	}
	
	protected void RemoveNotification()
	{
		if (m_isNotification)
		{
			NotificationSystemExtension.GetInstance().RemoveNotificationEditable();
			m_isNotification = false;
		}
	}
	
	protected string GetStormName()
	{
		switch( m_plugin.GetStormType() )
		{
			case AnomalyStormType.Storm:
				return ANOMALY_STORM_NAME;
			case AnomalyStormType.Rad:
				return RAD_STORM_NAME;
		}
		
		return "NO NAME";
	}
};
