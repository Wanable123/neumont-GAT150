#include "AudioComponent.h"
#include "../Engine.h"
namespace livewire 
{
	AudioComponent::~AudioComponent()
	{
		m_channel.Stop();
	}
	void AudioComponent::Initialize()
	{
		if (playOnAwake) {
			g_audioSystem.PlayAudio(m_soundname, m_volume, m_pitch, m_loop);

		}
	}
	void AudioComponent::Update()
	{
	}

	void AudioComponent::Play()
	{
		m_channel.Stop();
		m_channel = g_audioSystem.PlayAudio(m_soundname, m_volume, m_pitch, m_loop);

	}

	void AudioComponent::Stop()
	{
		m_channel.Stop();
	}
	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool AudioComponent::Read(const rapidjson::Value& value)
	{

		g_audioSystem.AddAudio(m_soundname,m_soundname);

		return true;
	}
}
