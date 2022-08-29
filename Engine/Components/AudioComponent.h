#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"

namespace livewire
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

		void Initialize() override;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		AudioChannel m_channel;

		std::string m_soundname;
		bool playOnAwake = false;
		float m_pitch = 1;
		float m_volume = 1;
		bool m_loop = false;
	};
}