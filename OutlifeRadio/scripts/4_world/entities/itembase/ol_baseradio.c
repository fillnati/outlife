class Ol_BaseRadio extends ItemBase
{	
	const string TarasChubay		= "TarasChubay_Cassette_SoundSet";	
	const string VV					= "VV_Cassette_SoundSet";
	const string Empty				= "Empty_Cassette_SoundSet";
	
	const string SOUND_TURN_ON			= "turnOnRadio_SoundSet";			
	const string SOUND_TURN_OFF			= "turnOffRadio_SoundSet";			

	static ref array<Object> m_chests;

	ref protected EffectSound m_PlaySoundLoop_St;

	protected EffectSound m_SoundTurnOn;									
	protected EffectSound m_SoundTurnOff;									

	void Ol_BaseRadio()
	{
		m_PlaySoundLoop_St = new EffectSound;
	}

	override void SetActions()
	{
		super.SetActions();

		AddAction(ActionTurnOnWhileInHands);
		AddAction(ActionTurnOffWhileInHands);
	}

	void OnSwitchOn()
	{
		super.OnSwitchOn();
		SoundTurnOn();
		PlaySong();
		SetSynchDirty();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
		StopSong();
		SoundTurnOff();
		SetSynchDirty();
	}

	override bool CanReceiveAttachment(EntityAI attachment, int slotId) 
	{
		ItemBase item = ItemBase.Cast(attachment);

		if (!item.IsRuined() && !this.GetCompEM().IsWorking())
		{
			return true;
		}

		return false;
	}

	override bool CanReleaseAttachment(EntityAI attachment)
	{
		if (this.GetCompEM().IsWorking())
		{
			return false;
		}
		return true;
	}

	void PlaySong()
	{
		for (int i = 0; i < CassettesAsAtt.Count(); i++)
		{
			Entity Attached_Cassette = EntityAI.Cast(this.FindAttachmentBySlotName("Ol_BaseCassette"));

			if (Attached_Cassette == NULL)
			{
				Print(":::DEBUG::: NO CASSETTE ATTACHED");
			}

			else
			{
				if (Attached_Cassette.IsKindOf(CassettesAsAtt.Get(i)))
				{
					string ActualAttachedCasette = Attached_Cassette.GetType();

					switch (ActualAttachedCasette)
					{
					
					case "Ol_TarasChubay_Cassette":
					{
						PlaySoundSetLoop(m_PlaySoundLoop_St, TarasChubay, 0.5, 0.6);
					}
					break;
					
					case "Ol_VV_Cassette":
					{
						PlaySoundSetLoop(m_PlaySoundLoop_St, VV, 0.5, 0.6);
					}
					break;
					
					case "Ol_BaseCassette":
					{
						PlaySoundSetLoop(m_PlaySoundLoop_St, Empty, 0.5, 0.6);
					}
					break;
					
					default:
						Print(":::DEBUG::: Could Not Play A Song- Please Insert Casette");
						break;
					}
				}
			}
		}
	}

	void StopSong()
	{
		if (GetGame().IsMultiplayer() && GetGame().IsServer())
		{
			StopSoundSet(m_PlaySoundLoop_St);
		}

		if (GetGame().IsMultiplayer() && GetGame().IsClient())
		{
			StopSoundSet(m_PlaySoundLoop_St);
		}
	}

	protected void SoundTurnOn()
	{
		PlaySoundSet(m_SoundTurnOn, SOUND_TURN_ON, 0.0, 0.0);
	}

	protected void SoundTurnOff()
	{
		PlaySoundSet(m_SoundTurnOff, SOUND_TURN_OFF, 0.0, 0.0);
	}
};
class Ol_Vesna_Radio : Ol_BaseRadio {};
class Ol_Milga_Radio : Ol_BaseRadio {};
class Ol_Panasonic_Radio : Ol_BaseRadio {};
class Ol_BaseCassette extends ItemBase{};
class Ol_TarasChubay_Cassette extends ItemBase{};
class Ol_VV_Cassette extends ItemBase{};