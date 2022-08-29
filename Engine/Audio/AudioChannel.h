#pragma once


namespace FMOD
{
	class System;
	class Sound;
	class Channel;
}

namespace livewire {
	class AudioChannel
	{
	public:
		AudioChannel(){}
		AudioChannel(FMOD::Channel* channel) { m_channel = channel; }

		bool isPlaying();
		void Stop();

		void SetPitch(float pitch);
		float GetPitch();


		void SetVolume(float volume);
		float GetVolume();

	private:
		FMOD::Channel* m_channel = nullptr;
	};

}