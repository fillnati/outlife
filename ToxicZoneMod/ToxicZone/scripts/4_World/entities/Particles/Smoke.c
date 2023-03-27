class GreenSmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void GreenSmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~GreenSmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}

class PurpleSmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void PurpleSmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_PURPLESMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_PurpleSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_PURPLESMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_PURPLESMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_PURPLESMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~PurpleSmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}

class BlueSmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void BlueSmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~BlueSmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}
class RedSmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void RedSmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~RedSmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}
class GreySmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void GreySmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~GreySmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}

class GreenSmoke2Long extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void GreenSmoke2Long()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE2, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE2, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE2, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE2, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~GreenSmoke2Long()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}

class WhiteSmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void WhiteSmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_WHITESMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_WHITESMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_WHITESMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_WHITESMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~WhiteSmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}

class MustardSmokeLong extends House
{
	//Particle m_ParticleEfx;
	Particle m_ParticleEfx1;
	Particle m_ParticleEfx2;
	Particle m_ParticleEfx3;
	Particle m_ParticleEfx4;
	vector 	m_ParticleLocalPos1 = Vector(70, 0, 70);
	vector 	m_ParticleLocalPos2 = Vector(-70, 0, 70);
	vector 	m_ParticleLocalPos3 = Vector(-70, 0, -70);
	vector 	m_ParticleLocalPos4 = Vector(70, 0, -70);

	void MustardSmokeLong()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx1 = Particle.PlayOnObject(ParticleList.TOXICZONE_MUSTARDSMOKE, this, m_ParticleLocalPos1, Vector(0,0,0), true);
			//m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this);
			m_ParticleEfx2 = Particle.PlayOnObject(ParticleList.TOXICZONE_MUSTARDSMOKE, this, m_ParticleLocalPos2, Vector(0,0,0), true);
			m_ParticleEfx3 = Particle.PlayOnObject(ParticleList.TOXICZONE_MUSTARDSMOKE, this, m_ParticleLocalPos3, Vector(0,0,0), true);
			m_ParticleEfx4 = Particle.PlayOnObject(ParticleList.TOXICZONE_MUSTARDSMOKE, this, m_ParticleLocalPos4, Vector(0,0,0), true);
		}
	}

	void ~MustardSmokeLong()
	{
		if (m_ParticleEfx1)
			m_ParticleEfx1.Stop();
		if (m_ParticleEfx2)
			m_ParticleEfx2.Stop();
		if (m_ParticleEfx3)
			m_ParticleEfx3.Stop();
		if (m_ParticleEfx4)
			m_ParticleEfx4.Stop();
	}
}

class GreenSmoke extends House
{
	Particle m_ParticleEfx;

	void GreenSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE, this);
		}
	}

	void ~GreenSmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class PurpleSmoke extends House
{
	Particle m_ParticleEfx;

	void PurpleSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_PURPLESMOKE, this);
		}
	}

	void ~PurpleSmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class BlueSmoke extends House
{
	Particle m_ParticleEfx;

	void BlueSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESMOKE, this);
		}
	}

	void ~BlueSmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class RedSmoke extends House
{
	Particle m_ParticleEfx;

	void RedSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSMOKE, this);
		}
	}

	void ~RedSmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class GreySmoke extends House
{
	Particle m_ParticleEfx;

	void GreySmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREYSMOKE, this);
		}
	}

	void ~GreySmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class GreenSmoke2 extends House
{
	Particle m_ParticleEfx;

	void GreenSmoke2()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSMOKE2, this);
		}
	}

	void ~GreenSmoke2()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class MustardSmoke extends House
{
	Particle m_ParticleEfx;

	void MustardSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_MUSTARDSMOKE, this);
		}
	}

	void ~MustardSmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class WhiteSmoke extends House
{
	Particle m_ParticleEfx;

	void WhiteSmoke()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_WHITESMOKE, this);
		}
	}

	void ~WhiteSmoke()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class GreenSpore extends House
{
	Particle m_ParticleEfx;

	void GreenSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_GREENSPORE, this);
		}
	}

	void ~GreenSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class PurpleSpore extends House
{
	Particle m_ParticleEfx;

	void PurpleSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_PURPLESPORE, this);
		}
	}

	void ~PurpleSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class BlueSpore extends House
{
	Particle m_ParticleEfx;

	void BlueSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_BLUESPORE, this);
		}
	}

	void ~BlueSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class RedSpore extends House
{
	Particle m_ParticleEfx;

	void RedSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_REDSPORE, this);
		}
	}

	void ~RedSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class MustardSpore extends House
{
	Particle m_ParticleEfx;

	void MustardSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_MUSTARDSPORE, this);
		}
	}

	void ~MustardSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}

class WhiteSpore extends House
{
	Particle m_ParticleEfx;

	void WhiteSpore()
	{
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			m_ParticleEfx = Particle.PlayOnObject(ParticleList.TOXICZONE_WHITESPORE, this);
		}
	}

	void ~WhiteSpore()
	{
		if (m_ParticleEfx)
			m_ParticleEfx.Stop();
	}
}
