////////////////////////////////////////////////////////////////////
//DeRap: sounds\config.bin
//Produced from mikero's Dos Tools Dll version 9.24
//https://mikero.bytex.digital/Downloads
//'now' is Thu Mar 30 18:34:17 2023 : 'file' last modified on Thu Mar 30 18:34:17 2023
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class vwe_zone_broadcasting_sounds
	{
		author = "Virtual World Engineering";
		name = "vwe_zone_broadcasting_sounds";
		url = "";
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Sounds_Effects"};
	};
};
class CfgSoundShaders
{
	class Anomalystorm_Msg_RadStormStarted_01_SoundShader
	{
		samples[] = {{"\vwe\zone\broadcasting\sounds\messages\anomaly_storm\storm_started",1}};
		volume = 1;
		range = 50;
	};
	class Anomalystorm_Msg_AnomalyStormStarted_01_SoundShader: Anomalystorm_Msg_RadStormStarted_01_SoundShader{};
	class Anomalystorm_Msg_RadStormEnd_01_SoundShader
	{
		samples[] = {{"\vwe\zone\broadcasting\sounds\messages\anomaly_storm\storm_end",1}};
		volume = 1;
		range = 50;
	};
	class Anomalystorm_Msg_AnomalyStormEnd_01_SoundShader: Anomalystorm_Msg_RadStormEnd_01_SoundShader{};
	class Anomalystorm_Msg_RadStormWarning_01_SoundShader
	{
		samples[] = {{"\vwe\zone\broadcasting\sounds\messages\anomaly_storm\storm_warning",1}};
		volume = 1;
		range = 50;
	};
	class Anomalystorm_Msg_AnomalyStormWarning_01_SoundShader: Anomalystorm_Msg_RadStormWarning_01_SoundShader{};
};
class CfgSoundSets
{
	class Anomalystorm_Msg_RadStormStarted_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Msg_RadStormStarted_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Anomalystorm_Msg_AnomalyStormStarted_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Msg_AnomalyStormStarted_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Anomalystorm_Msg_RadStormEnd_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Msg_RadStormEnd_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Anomalystorm_Msg_AnomalyStormEnd_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Msg_AnomalyStormEnd_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Anomalystorm_Msg_RadStormWarning_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Msg_RadStormWarning_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
	class Anomalystorm_Msg_AnomalyStormWarning_01_SoundSet
	{
		soundShaders[] = {"Anomalystorm_Msg_AnomalyStormWarning_01_SoundShader"};
		volumeFactor = 1;
		frequencyFactor = 1;
		spatial = 1;
	};
};
