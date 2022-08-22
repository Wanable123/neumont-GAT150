#pragma once
#include "../Framework/Component.h"

namespace livewire
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;

		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		void Play();
		void Stop();

	public:
		std::string m_soundname;
		bool playOnAwake = false;
		float m_pitch = 1;
		bool m_loop = false;
	};
}