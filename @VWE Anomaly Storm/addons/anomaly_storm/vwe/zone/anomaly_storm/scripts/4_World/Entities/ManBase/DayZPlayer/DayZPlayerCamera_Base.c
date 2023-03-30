modded class DayZPlayerCameraBase
{
	void SetCameraShake(CameraShake cameraShake)
	{
		if (m_CameraShake)
			return;
		
		m_CameraShake = cameraShake;
	}
	
	bool IsCameraShake()
	{
		if (m_CameraShake)
			return true;
		return false;
	}
	
	bool IsCameraShakeLoop()
	{
		if (m_CameraShake)
			return m_CameraShake.Type() == CameraShakeLoop;
		return false;
	}
}