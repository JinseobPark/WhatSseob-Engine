#pragma once
#include <vector>
#include "sound.h"
#define GAU_THREAD_POLICY_MULTI 2

#include "../../extern/gorilla-audio/ga.h"
#include "../../extern/gorilla-audio/gau.h"


namespace whatsseob {
	namespace audio {

		class SoundManager
		{
		private:
			friend class Sound;

			static gau_Manager* m_Manager;
			static ga_Mixer* m_Mixer;

			static std::vector<Sound*> m_Sounds;
		public:
			static void init();
			static void add(Sound* sound);
			static Sound* get(const std::string& name);
			static void update();
			static void clean();
			
		private:
			SoundManager() {}
		};

	}
}