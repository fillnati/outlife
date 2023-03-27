class InsideTZ{

	string TZName;
	bool   TZStatut;

	void InsideTZ(){
		TZName="";
		TZStatut=false;
	}

}
modded class PlayerBase extends ManBase
{
	private int cpt=0;
	bool IsToxicSick;
	bool IsGasMaskWorking;
	int ToxicBloodLoss;
	int NbSickGivenforToxicSmoke;
	int GP5DamageGrenade;
	ref InsideTZ IsInside;
	bool IsMZAdmin;
	private ref array<string>m_SLOTS = {"Mask","Headgear","Body","Gloves","Legs","Feet"};
	//Particle m_ParticleOnPlayer;

	override void Init()
	{
		super.Init();
		IsInside = new InsideTZ;
		IsToxicSick=false;
		IsMZAdmin = false;
		RegisterNetSyncVariableBool("IsMZAdmin");
		RegisterNetSyncVariableBool("IsToxicSick");
	}

	void GiveToxicSickness(int value)
	{
		GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		InsertAgent(ToxicAgents.TOXICSICKNESS,value);
	}

	void SetIsToxicSick(bool rep)
	{
		IsToxicSick = rep;
		SetSynchDirty();
	}

	void SetIsMZAdmin(bool rep)
	{
		IsMZAdmin = rep;
		SetSynchDirty();
	}

	void GiveToxicSicknessForToxicSmoke()
	{
		GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
		InsertAgent(ToxicAgents.TOXICSICKNESS,NbSickGivenforToxicSmoke);
	}

	void SetToxicDamageOnClothes(bool isonlygasmask)
	{
		if (GetGame().IsServer() || !GetGame().IsMultiplayer())
		{
			#ifdef TZDEBUG
			GetTZLogger().LogInfo("SetToxicDamageOnClothes");
	  	#endif
			int count = m_SLOTS.Count();
			if(isonlygasmask) count = 1;
			for (int i = 0; i < count ;i++)
			{
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(i));
				if(SuitsPart == NULL || SuitsPart.IsRuined())return;
				float Health = SuitsPart.GetMaxHealth();
				#ifdef TZDEBUG
				GetTZLogger().LogInfo("SuitsPart:"+SuitsPart.GetType()+"Max health:"+Health.ToString());
		  	#endif
				SuitsPart.AddHealth( "", "", -Health*(GetTZGNRConfig().SuitsDamage*0.01));
				#ifdef TZDEBUG
				GetTZLogger().LogInfo("SuitsPart:Current Health"+SuitsPart.GetHealth("","").ToString());
		  	#endif
			}
		}
	}

	override void EEHitBy(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		super.EEHitBy(damageResult,damageType,source,component,dmgZone,ammo,modelPos,speedCoef);
		/*if(IsInside.TZStatut==true && IsToxicSick==false)
		{
			cpt+=1;
			if(cpt==5)
			{
				cpt=0;
				NBCSuitsLite();
			}
		}*/
	}

	void GasMaskCheck()
	{
		if (GetGame().IsServer())
		{
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName(m_SLOTS.Get(0));
			if (SuitsPart == NULL || SuitsPart.IsRuined() || !SuitsPart.IsKindOf("GP5GasMask"))
			{
				GiveToxicSicknessForToxicSmoke();
				return;
			}
			else
			{
				if (SuitsPart != NULL && !SuitsPart.IsRuined())
				{
					SuitsPart.AddHealth( "", "", -GP5DamageGrenade);
				}
			}
		}
	}

	/*override void EEItemAttached(EntityAI item, string slot_name)
	{
		super.EEItemAttached(item, slot_name);
		//Print("item:"+item.ToString()+"slot:"+slot_name);
		if(IsInside.TZStatut==true && IsToxicSick==false)
		{
			NBCSuitsLite();
		}
	}

	override void EEItemDetached(EntityAI item, string slot_name)
	{
		super.EEItemDetached(item, slot_name);
		//Print("item:"+item.ToString()+"slot:"+slot_name);
		if(IsInside.TZStatut==true && IsToxicSick==false)
		{
			NBCSuitsLite();
		}
	}*/

}
