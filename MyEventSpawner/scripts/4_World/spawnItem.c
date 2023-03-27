class MyItemSpawn {
	const string textHello = "Hello World";
	const string MyItemType = "Barrel_Red";
	const vector MyCoords = Vector(3825.65332, 330.264191, 10793.583008);

	void ItemSpawnFunction() {
		Print(textHello + MyCoords);
		GetGame().CreateObjectEx(MyItemType, MyCoords, ECE_PLACE_ON_SURFACE);
	}
}
