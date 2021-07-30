#pragma once
#include <string>
#include "../utils/stringutils.h"
#include "../../extern/gorilla-audio/ga.h"
#include "../../extern/gorilla-audio/gau.h"

namespace whatsseob {
	namespace audio {
		class Sound
		{
		private:
			std::string m_Name;
			std::string m_Filename;

			ga_Sound* m_Sound;
			ga_Handle* m_Handle;
			gc_int32 m_Position;

			bool m_ResumeLoop;
			bool m_Playing;
			float m_Gain;
		public:
			Sound(const std::string& name, const std::string& filename);
			~Sound();
			void play();
			void loop();
			void pause();
			void resume();
			void stop();

			void setGain(float gain);

			inline float getGain() const { return m_Gain; }
			inline const bool isPlaying() const { return m_Playing; }
			inline const std::string& getName() const { return m_Name; }
			inline const std::string& getFileName() const { return m_Filename; }

			friend void destroyOnFinish(ga_Handle* in_handle, void* in_context);
			friend void loopOnFinish(ga_Handle* in_handle, void* in_context);

		};
	}

}