class StaticToxicZoneLocationsClient
{
  ref array<string> Statut;
  ref array<float> X;
  ref array<float> Y;
  ref array<float> Radius;
  ref array<bool> IsSquareZone;
  ref array<float> X1;
  ref array<float> Y1;
  ref array<float> X2;
  ref array<float> Y2;
  ref array<bool> IsMsgActive;
  ref array<string> MsgEnterZone;
  ref array<string> MsgExitZone;
  ref array<bool> IsOnlyGasMask;


    void StaticToxicZoneLocationsClient(ref array<ref StaticToxicZoneLocation> temp_staticToxicZoneLocation)
	  {
      IsMsgActive = new array<bool>;
      Statut = new array<string>;
      X = new array<float>;
      Y = new array<float>;
      Radius = new array<float>;
      IsSquareZone = new array<bool>;
      X1 = new array<float>;
      Y1 = new array<float>;
      X2 = new array<float>;
      Y2 = new array<float>;
      MsgEnterZone = new array<string>;
      MsgExitZone = new array<string>;
      IsOnlyGasMask = new array<bool>;

      TransferToxicConfig(temp_staticToxicZoneLocation);
    }

    void TransferToxicConfig(ref array<ref StaticToxicZoneLocation> temp_staticToxicZoneLocation)
    {
      int cpt = -1 + temp_staticToxicZoneLocation.Count();
      for(int i = 0; i<=cpt ; i++)
      {
        Statut.Insert(temp_staticToxicZoneLocation.Get(i).ToxicZoneStatut);
        X.Insert(temp_staticToxicZoneLocation.Get(i).X);
        Y.Insert(temp_staticToxicZoneLocation.Get(i).Y);
        X1.Insert(temp_staticToxicZoneLocation.Get(i).X1);
        Y1.Insert(temp_staticToxicZoneLocation.Get(i).Y1);
        X2.Insert(temp_staticToxicZoneLocation.Get(i).X2);
        Y2.Insert(temp_staticToxicZoneLocation.Get(i).Y2);
        Radius.Insert(temp_staticToxicZoneLocation.Get(i).Radius);
        IsSquareZone.Insert(temp_staticToxicZoneLocation.Get(i).IsSquareZone);
        IsMsgActive.Insert(temp_staticToxicZoneLocation.Get(i).IsMsgActive);
        MsgEnterZone.Insert(temp_staticToxicZoneLocation.Get(i).MsgEnterZone);
        MsgExitZone.Insert(temp_staticToxicZoneLocation.Get(i).MsgExitZone);
        IsOnlyGasMask.Insert(temp_staticToxicZoneLocation.Get(i).IsOnlyGasMask);
      }
    }
}
