modded class ModifiersManager
{
	override void Init()
	{
		super.Init();
		AddModifier(new ToxicSicknessMdfr);
		AddModifier(new ToxicCureMdfr);
	}
}
