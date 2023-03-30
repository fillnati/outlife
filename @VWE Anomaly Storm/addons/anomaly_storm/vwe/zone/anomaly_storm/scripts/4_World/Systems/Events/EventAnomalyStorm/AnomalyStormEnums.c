enum AnomalyStormType
{
	NotUsed,
	Storm,
	Rad
}

enum AnomalyStormState
{
	Idle,
	Wait,
	Warning,
	Preparation,
	Active
}

enum AnomalyStormPhase
{
	None,
	BeforeStart,
	Start,
	AfterStart,
	BeforeRun,
	Run,
	AfterRun,
	BeforeEnd,
	End,
	AfterEnd,
	Reset
}
