#include "sound.h"
#include "sound_manager.h"
#include <iostream>

namespace whatsseob {
	namespace audio {
		void destroyOnFinish(ga_Handle* in_handle, void* in_context);
		void loopOnFinish(ga_Handle* in_handle, void* in_context);

		Sound::Sound(const std::string& name, const std::string& filename)
			: m_Name(name), m_Filename(filename), m_Playing(false)
		{
			std::vector<std::string> split = split_string(m_Filename, '.');
			if (split.size() < 2)
			{
				std::cout << "sound, invalid file name " << m_Filename << std::endl;
				return;
			}
			m_Sound = gau_load_sound_file(filename.c_str(), split.back().c_str());
			if (m_Sound == nullptr)
			{
				std::cout << "sound, not load file " << m_Filename << std::endl;
				return;
			}
		}
		Sound::~Sound()
		{
			ga_sound_release(m_Sound);
		}
		void Sound::play()
		{
			m_Playing = true;
			gc_int32 quit = 0;
			m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &destroyOnFinish, &quit, NULL);
			m_Handle->sound = this;
			ga_handle_play(m_Handle);

		}
		void Sound::loop()
		{
			gc_int32 quit = 0;
			m_Playing = true;
			m_Handle = gau_create_handle_sound(SoundManager::m_Mixer, m_Sound, &loopOnFinish, &quit, NULL);
			m_Handle->sound = this;
			ga_handle_play(m_Handle);
		}

		void Sound::resume()
		{
			if (m_Playing)
				return;
			m_Playing = true;
			ga_handle_play(m_Handle);
		}

		void Sound::pause()
		{
			if (!m_Playing)
				return;
			m_Playing = false;
			ga_handle_stop(m_Handle);
		}
		void Sound::stop()
		{
			if (!m_Playing)
				return;
			ga_handle_stop(m_Handle);
			m_Playing = false;

		}

		void Sound::setGain(float gain)
		{
			if (!m_Playing)
			{
				std::cout << "no sound no gain" << std::endl;
				return;
			}
			m_Gain = gain;
			ga_handle_setParamf(m_Handle, GA_HANDLE_PARAM_GAIN, gain);
		}

		static void destroyOnFinish(ga_Handle* in_handle, void* in_context)
		{
			Sound* sound = (Sound*)in_handle->sound;
			sound->stop();

		}
		static void loopOnFinish(ga_Handle* in_handle, void* in_context)
		{
			Sound* sound = (Sound*)in_handle->sound;
			sound->loop();
			ga_handle_destroy(in_handle);
		}
	}
}