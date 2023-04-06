//Made by Pechyvo
class CfgPatches
{
	class AWS_Fix
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
	class Inventory_Base;
	//Advanced Weapon Scopes
	class AD_B13Mount: Inventory_Base
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class AD_MosinMount: Inventory_Base
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class ItemOptics;
	class AD_DHF5_Base: ItemOptics
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class AD_LeupoldMk4_Base: ItemOptics
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class AD_NFATACR_Base: ItemOptics
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class AD_NFATACR_1_8_Base: ItemOptics
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class AD_Pilad_Base: ItemOptics
	{
		repairableWithKits[]={8};
		repairCosts[]={25};
	};
	class AD_PVS4_Base: ItemOptics
	{
		repairableWithKits[]={7};
		repairCosts[]={50};
	};
	//AWS NFATACR_RMR Fix
	class AD_NFATACR_BaseFix: ItemOptics
	{
		scope=0;
		displayName="$STR_AD_NFATACR0";
		descriptionShort="$STR_AD_NFATACR1";
		model="AdvancedWeaponScopes\NF_ATACR\nfatacr.p3d";
		animClass="Binoculars";
		rotationFlags=4;
		reversed=0;
		weight=1113;
		itemSize[]={5,1};
		inventorySlot[]=
		{
			"sniperOptics",
			"weaponOpticsHunting",
			"weaponOptics"
		};
		simulation="itemoptics";
		dispersionModifier=-0.001;
		dispersionCondition="true";
		recoilModifier[]={1,1,1};
		memoryPointCamera="eyeScope";
		cameraDir="cameraDir";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base_damage.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base_destruct.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class OpticsInfo
		{
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			useModelOptics=1;
			modelOptics="AdvancedWeaponScopes\NF_ATACR\NFATACR_reticle.p3d";
			preloadOpticType="Preload2DOptic_NFATACR";
			opticsDisablePeripherialVision=0.67000002;
			opticsFlare=1;
			opticsPPEffects[]=
			{
				"OpticsCHAbera3",
				"OpticsBlur1"
			};
			opticsZoomMin="0.3926/7";
			opticsZoomMax="0.3926/35";
			opticsZoomInit="0.3926/7";
			discretefov[]=
			{
				"0.3926/7",
				"0.3926/12",
				"0.3926/22",
				"0.3926/35"
			};
			discreteInitIndex=0;
			distanceZoomMin=100;
			distanceZoomMax=2000;
			discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.43000001,0.1};
			PPLensProperties[]={0.30000001,0.15000001,0,0};
			PPBlurProperties=0.30000001;
		};
		class AnimationSources
		{
			class hide
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
		};
	};
	class Ol_NFATACR_B13_RMRFix: AD_NFATACR_BaseFix
	{
		scope=2;
		displayName="$STR_AD_NFATACR3";
		descriptionShort="$STR_AD_NFATACR1";
		model="AdvancedWeaponScopes\B13Mount\b13_NFATACR_rmr.p3d";
		inventorySlot[]=
		{
			"weaponOpticsAK"
		};
		weight=1500;
		itemSize[]={5,2};
		hiddenSelections[]=
		{
			"reddot"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
		attachments[]=
		{
			"BatteryD"
		};
		class OpticsInfo
		{
			memoryPointCamera="eyeScope";
			cameraDir="cameraDir";
			useModelOptics=1;
			modelOptics="AdvancedWeaponScopes\NF_ATACR\NFATACR_reticle.p3d";
			preloadOpticType="Preload2DOptic_NFATACR";
			opticsDisablePeripherialVision=0.67000002;
			opticsFlare=1;
			opticsPPEffects[]=
			{
				"OpticsCHAbera3",
				"OpticsBlur1"
			};
			opticsZoomMin="0.3926/7";
			opticsZoomMax="0.3926/35";
			opticsZoomInit="0.3926/7";
			discretefov[]=
			{
				"0.3926/7",
				"0.3926/12",
				"0.3926/22",
				"0.3926/35"
			};
			discreteInitIndex=0;
			distanceZoomMin=300;
			distanceZoomMax=2000;
			discreteDistance[]={300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.43000001,0.1};
			PPLensProperties[]={0.30000001,0.15000001,0,0};
			PPBlurProperties=0.30000001;
			opticSightTexture="dz\weapons\attachments\optics\data\collimdot_red_ca.paa";
		};
		class OpticsInfoWeaponOverride
		{
			memoryPointCamera="eyeIronsights";
			cameraDir="cameraDirIronsights";
			opticsZoomMin=0.52359998;
			opticsZoomMax=0.52359998;
			opticsZoomInit=0.52359998;
			distanceZoomMin=50;
			distanceZoomMax=150;
			discreteDistance[]={50,150};
			discreteDistanceInitIndex=0;
			PPMaskProperties[]={0.5,0.5,0.375,0.050000001};
			PPLensProperties[]={0.5,0.15000001,0,0};
			PPBlurProperties=0.60000002;
			PPDOFProperties[]={1,0.1,20,200,4,10};
		};
		repairableWithKits[]={7};
		repairCosts[]={25};
		class EnergyManager
		{
			hasIcon=1;
			energyUsagePerSecond=0.02;
			plugType=1;
			attachmentAction=1;
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope.rvmat",
								"AdvancedWeaponScopes\RMR\data\offsetmount.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope.rvmat",
								"AdvancedWeaponScopes\RMR\data\offsetmount.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base_damage.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope_damage.rvmat",
								"AdvancedWeaponScopes\RMR\data\offsetmount_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base_damage.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope_damage.rvmat",
								"AdvancedWeaponScopes\RMR\data\offsetmount_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"AdvancedWeaponScopes\NF_ATACR\data\base_destruct.rvmat",
								"AdvancedWeaponScopes\NF_ATACR\data\scope_destruct.rvmat",
								"AdvancedWeaponScopes\RMR\data\offsetmount_destruct.rvmat"
							}
						}
					};
				};
			};
		};
	};
};