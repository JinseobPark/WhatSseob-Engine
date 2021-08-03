#pragma once

#include "graphics/window.h"
#include "graphics/batchRenderer2D.h"
#include "graphics/renderer2d.h"
#include "graphics/sprite.h"
#include "graphics/layers/layer.h"

#include "maths/maths.h"
#include "utils/timer.h"

namespace whatsseob {
	
	class Whatsseob
	{
	private:
		graphics::Window* m_Window;
		Timer* m_Timer;
		unsigned int m_FramesPerSecond, m_UpdatePerSecond;
	protected:
		Whatsseob() : m_FramesPerSecond(0), m_UpdatePerSecond(0)
		{

		}
		virtual ~Whatsseob() 
		{
			delete m_Window;
			delete m_Timer;
		}

		graphics::Window* createWindow(const char* name, int width, int height)
		{
			m_Window = new graphics::Window(name, width, height);
			return m_Window;
		}

	public:
		void start()
		{
			init();
			run();
		}
	protected:
		// initialize
		virtual void init() = 0;
		// per second
		virtual void tick() {}
		//60times per second
		virtual void update() {}
		//runs as fast as possible
		virtual void render() = 0;
		
		const unsigned int getFPS() const { return m_FramesPerSecond; }
		const unsigned int getUPS() const { return m_UpdatePerSecond; }
	private:
		void run()
		{
			m_Timer = new Timer();
			float timer = 0.0f;
			float updateTimer = 0.0f;
			float updateTick = 1.0f / 60.0f;
			unsigned int frames = 0;
			unsigned int updates = 0;
			while (!m_Window->closed())
			{
				m_Window->clear();
				if (m_Timer->elapsed() - updateTimer > updateTick)
				{
					update();
					updates++;
					updateTimer += updateTick;
				}

				render();
				m_Window->update();
				frames++;
				if (m_Timer->elapsed() - timer > 1.0f)
				{
					timer += 1.0f;
					m_FramesPerSecond = frames;
					m_UpdatePerSecond = updates;
					frames = 0;
					updates = 0;
					tick();
				}
			}
		}
	};
}

