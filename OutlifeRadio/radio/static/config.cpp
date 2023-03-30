//Made by Pechyvo
class CfgPatches
{
	class Ol_Static_Radio
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class HouseNoDestruct;
	//Milga
	class Ol_Static_TarasChubay_Milga: HouseNoDestruct
	{
		scope=2;
		model="DZ\gear\radio\unitra_wilga.p3d";
	};
	class Ol_Static_VV_Milga: Ol_Static_TarasChubay_Milga
	{
		scope=2;
	};
	//Vesna
	class Ol_Static_TarasChubay_Vesna: HouseNoDestruct
	{
		scope=2;
		model="OutlifeRadio\Radio\vesna.p3d";
	};
	class Ol_Static_VV_Vesna: Ol_Static_TarasChubay_Vesna
	{
		scope=2;
	};
	//Panasonic
	class Ol_Static_TarasChubay_Panasonic: HouseNoDestruct
	{
		scope=2;
		model="OutlifeRadio\Radio\panasonic.p3d";
	};
	class Ol_Static_VV_Panasonic: Ol_Static_TarasChubay_Panasonic
	{
		scope=2;
	};
};
