class MyItemSpawn {
	const string textHello = "Hello World";
	const string MyItemType = "Barrel_Red";
	

	void ItemSpawnFunction() {
		vector pos = <9435.488281, 6.012424, 2007.998901>;
		Print(textHello + pos);
		GetGame().CreateObjectEx(MyItemType, pos, ECE_PLACE_ON_SURFACE);
	}
}
