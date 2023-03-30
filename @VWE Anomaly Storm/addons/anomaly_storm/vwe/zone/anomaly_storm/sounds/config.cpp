////////////////////////////////////////////////////////////////////
//DeRap: sounds\config.bin
//Produced from mikero's Dos Tools Dll version 9.24
//https://mikero.bytex.digital/Downloads
//'now' is Thu Mar 30 19:14:09 2023 : 'file' last modified on Fri Mar 24 19:41:46 2023
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class VWE_Zone_Anomaly_Storm_Sounds
	{
		author = "Virtual World Engineering";
		name = "VWE_Zone_Anomaly_Storm_Sounds";
		url = "";
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Effects"};
	};
};
class CfgSoundShaders
{
	class Anomalystorm_Alarm_01_SoundShader
	{
		samples[] = {{"\vwe\zone\anomaly_storm\sounds\alarm_01",1}};
		volume = 1;
		range = 250;
	};
	class Radstorm_Alarm_01_SoundShader: Anomalystorm_Alarm_01_SoundShader{};
	class Radstorm_Background_SoundShader
	{
		samples[] = {{"\vwe\zone\anomaly_storm\sounds\radstorm_background",1}};
		volume = 1;
	};
};
class CfgSoundSets
{
	class Anomalystorm_Alarm_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Alarm_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Radstorm_Alarm_01_SoundSet
	{
		soundShaders[] = {"Radstorm_Alarm_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Radstorm_Background_SoundSet
	{
		soundShaders[] = {"Radstorm_Background_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 0;
	};
};
