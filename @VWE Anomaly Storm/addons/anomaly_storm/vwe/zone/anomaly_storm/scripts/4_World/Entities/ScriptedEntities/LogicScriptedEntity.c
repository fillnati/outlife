class LogicScriptedEntity : ScriptedEntity
{
	private bool m_intialized;
	private EntityAI m_parent;
	
	void LogicScriptedEntity()
	{
		m_intialized = false;
		
		SetEventMask(EntityEvent.INIT | EntityEvent.FRAME);
		SetFlags(EntityFlags.ACTIVE, false);
	}
	
	void Init(EntityAI parent)
	{
		m_parent = parent;
		
		if (m_parent)
		{
			m_intialized = true;			
		}
	}
	
	override void EOnInit(IEntity other, int extra)
	{

	}
	
	override void EOnFrame(IEntity other, float timeSlice)
	{
		if (!m_intialized || !m_parent)
			return;
		
		m_parent.EOnFrame(other, timeSlice);
	}
}