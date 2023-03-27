class MovingToxicZoneLocation
{
  string      MovingToxicZoneStatut;
  bool        IsMsgActive;
  string      MsgEnterZone, MsgExitZone;
  float       StartX, StartY, EndX, EndY, Radius;
	float       Coeff,YtoOrigin,Chance;
	int         Speed;
	int         Norme;
  int         NbSickGiven;
	bool        IsOnlyGasMask;
	string      ParticleName;

    void MovingToxicZoneLocation(int nbsickgiven=0,bool ismsgactive=false,string msgenter="", string msgexit="",float chance=0.0,bool isonlygasmask=0,string particlename="", string movingstatut="", int speed=0, float startx=0.0, float starty=0.0, float endx=0.0, float endy=0.0, float radius=0.0)
	   {
        NbSickGiven = nbsickgiven;
        IsMsgActive = ismsgactive;
        MsgEnterZone = msgenter;
        MsgExitZone = msgexit;
    		Chance=chance;
    		ParticleName=particlename;
    		IsOnlyGasMask=isonlygasmask;
        MovingToxicZoneStatut = movingstatut;
    		Speed=speed;
        StartX = startx;
        StartY = starty;
    		EndX = endx;
    		EndY = endy;
        Radius = radius;
    		YtoOrigin=StartY-Coeff*StartX;
        if(startx==0.0 && starty==0.0 && endx==0.0 && endy==0.0)return;
        Coeff=(EndY-StartY)/(EndX-StartX);
    		Norme = DoNorm();
     }

	int DoNorm()
	{
		private int X,Y;
		if(StartX>EndX)
		{
			X=StartX-EndX;
		}else X=EndX-StartX;
		if(StartY>EndY)
		{
			X=StartY-EndY;
		}else Y=EndY-StartY;
		return Math.Sqrt(Math.Pow(X,2)+Math.Pow(Y,2));
	}

}
