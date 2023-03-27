class TZClotheConfigTemp
{
  string SlotName;
  ref array<string> ClothesNames;
  ref array<int> Protection;

  void TZClotheConfigTemp(int i, ref TZClotheProtectionSettings m_config)
  {
    SlotName = m_config.TZListSlotProtection.Get(i).SlotName;
    ClothesNames = new array<string>;
    Protection = new array<int>;
    for(int k=0;k<m_config.TZListSlotProtection.Get(i).ListProtections.Count();k++)
    {
      ClothesNames.Insert(m_config.TZListSlotProtection.Get(i).ListProtections.Get(k).ClotheName);
      Protection.Insert(m_config.TZListSlotProtection.Get(i).ListProtections.Get(k).Protection);
    }
  }
}
