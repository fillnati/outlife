modded class PluginTransmissionAgents extends PluginBase
{
	void PluginTransmissionAgents()
	{
		//add new agents here
		RegisterAgent(new ToxicAgent);
	}
};
