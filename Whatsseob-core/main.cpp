
#if 0
#include "src/graphics/window.h"
#include "src/graphics/shader.h"
#include "src/utils/timer.h"

#include "src/graphics/renderer2d.h"
#include "src/graphics/batchRenderer2D.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/sprite.h"

#include "src/graphics/layers/group.h"
#include "src/graphics/texture.h"

#include "src/audio/sound_manager.h"

#include "tilelayer.h"


int main(void)
{
	using namespace whatsseob;
	using namespace graphics;
	using namespace maths;
	using namespace audio;


	Window window("HelloSeob!", 960, 540);


	mat4 ortho = mat4::orthographic(16.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader* s1 =  new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s1;
	shader.enable();
	shader.setUniform2f("light_pos", maths::vec2(4.0f, 1.5f));


	TileLayer layer(&shader);


	Texture* textures[] =
	{
		new Texture("test.png"),
		new Texture("test2.png"),
		new Texture("test3.png")
	};

	for (float y = -9.0f; y < 9.0f; y ++)
	{
		for (float x = -16.0f; x < 16.0f; x ++)
		{
			int r = rand() % 256;
			int col = 0xffff00 << 8 | r;

			if(rand() % 4 == 0)
				layer.add(new Sprite(x, y, 0.9f, 0.9f, col));
			else
				layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand() % 3]));

		}
	}

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	SoundManager::add(new Sound("test", "test.wav"));
	SoundManager::get("test")->play();

	Timer time;
	float timer = 0;
	unsigned int frames = 0;

	float t = 0.0f;
	float gain = 0.5f;
	SoundManager::get("test")->setGain(gain);

	while (!window.closed())
	{
		t += 0.001f;

		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", maths::vec2((float)(x * 32.0f / window.getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window.getHeight())));

		layer.render();

		if (window.isMouseButtonClicked(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "K" << std::endl;
		if (window.isMouseButtonClicked(GLFW_MOUSE_BUTTON_LEFT))
			std::cout << "twoice" << std::endl;

		const std::vector<Renderable2D*>& rs = layer.getRenderables();
		for (int i = 0; i < rs.size(); i++)
		{
			float c = sin(t) / 2.0f + 0.5f;
			rs[i]->setColor(maths::vec4(c, 0, 1, 1));
		}

		if (window.isKeyTyped(GLFW_KEY_P))
			SoundManager::get("test")->loop();

		if (window.isKeyTyped(GLFW_KEY_UP))
		{
			gain += 0.05f;
			SoundManager::get("test")->setGain(gain);
		}
		if (window.isKeyTyped(GLFW_KEY_DOWN))
		{
			gain -= 0.05f;
			SoundManager::get("test")->setGain(gain);
		}
		if (window.isKeyTyped(GLFW_KEY_S))
		{
			SoundManager::get("test")->stop();
		}
		if (window.isKeyTyped(GLFW_KEY_1))
		{
			SoundManager::get("test")->pause();
		}
		if (window.isKeyTyped(GLFW_KEY_2))
		{
			SoundManager::get("test")->resume();
		}



	}

	for(int i = 0; i < 3; i++)
		delete textures[i];
	return 0;
}
#endif
