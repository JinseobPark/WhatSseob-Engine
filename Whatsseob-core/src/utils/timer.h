#pragma once

#include <chrono>

namespace whatsseob {
	class Timer
	{
	private:
		typedef std::chrono::high_resolution_clock resolutionClock;
		typedef std::chrono::duration<float, std::milli> milliseconds_type;
		std::chrono::time_point<resolutionClock> m_Start;
	public:
		Timer()
		{
			reset();
		}

		void reset()
		{
			m_Start = resolutionClock::now();
		}

		float elapsed()
		{
			return std::chrono::duration_cast<milliseconds_type>(resolutionClock::now() - m_Start).count() / 1000.0f;
		}
	};

}

#if 0
#include <Windows.h>
namespace whatsseob {
	class Timer
	{
	private:
		LARGE_INTEGER m_Start;
		double m_Frequency;
	public : 
		Timer()
		{
			LARGE_INTEGER frequency;
			QueryPerformanceFrequency(&frequency);
			m_Frequency = 1.0 / frequency.QuadPart;
			QueryPerformanceCounter(&m_Start);
		}

		void reset()
		{
			QueryPerformanceCounter(&m_Start);
		}

		float elapsed()
		{
			LARGE_INTEGER current;
			QueryPerformanceCounter(&current);
			unsigned __int64 cycles = current.QuadPart - m_Start.QuadPart;
			return (float)(cycles * m_Frequency);
		}

	};
}
#endif