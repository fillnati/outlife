class CameraShakeLoop : CameraShake
{
	void CameraShakeLoop(float strength_factor, float radius, float smoothness, float radius_decay_speed)
	{
		m_StregthFactor = strength_factor;
		m_Radius = radius;
		m_Smoothness = smoothness;
		m_RadiusDecaySpeed = radius_decay_speed;
	}
	
	void SetStregthFactor(float factor)
	{
		m_StregthFactor = factor;
	}
	
	float GetStregthFactor()
	{
		return m_StregthFactor;
	}
	
	override void Update(float delta_time, out float x_axis, out float y_axis)
	{
		if( m_RandomAngle >= 0 )
		{
			m_RandomAngle = -m_Radius + (Math.RandomFloat( -m_Radius / m_Smoothness, m_Radius / m_Smoothness));
		}
		else
		{
			m_RandomAngle = m_Radius + (Math.RandomFloat( -m_Radius / m_Smoothness, m_Radius / m_Smoothness));
		}
		
		x_axis = m_RandomAngle * m_StregthFactor;
		y_axis = m_RandomAngle * m_StregthFactor;
	}
}

