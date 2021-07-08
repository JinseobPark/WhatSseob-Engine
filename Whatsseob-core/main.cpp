#include "src/graphics/window.h"
#include "src//maths/maths.h"
#include "src/utils/fileutils.h"
#include "src/graphics/shader.h"

#include "src/graphics/buffers/buffer.h"
#include "src/graphics/buffers/indexbuffer.h"
#include "src/graphics/buffers/vertexarray.h"

#include "src/graphics/simple2drenderer.h"
#include "src/graphics/batchRenderer2D.h"


#include "src/graphics/renderer2d.h"

#include "src/graphics/static_sprite.h"
#include "src/graphics/sprite.h"
#include "src/utils/timer.h"
#include "src/graphics/layers/tilelayer.h"
#include "src/graphics/layers/group.h"
#include <time.h>

#define BATCH_RENDERER 1
#define TEST_50K_SPRITES 0

int main(void)
{
	using namespace whatsseob;
	using namespace graphics;
	using namespace maths;


	Window window("HelloSeob!", 960, 540);


	mat4 ortho = mat4::orthographic(16.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader* s1 =  new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader* s2 = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	Shader& shader = *s1;
	Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(&shader);
#if TEST_50K_SPRITES
	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, rand() % 1000 / 1000.0f, 1.0f, 1.0f)));
		}
	}
#else
	mat4 transform = mat4::rotation(45.0f, vec3(0, 0, 1)) * mat4::translation(vec3(-15.0f, 5.0f, 0.0f));
	Group* group = new Group(transform);
	group->add(new Sprite(0, 0, 6, 3, maths::vec4(1, 1, 1, 1)));
	group->add(new Sprite(0.5f, 0.5f, 5.0f, 2.0f, maths::vec4(1, 0, 1, 1)));

	Group* button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));
	button->add(new Sprite(0, 0, 6, 3, maths::vec4(1, 1, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 5.0f, 2.0f, maths::vec4(1, 0, 1, 1)));
	//group->add(button);

	layer.add(group);
	layer.add(button);

#endif

	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, maths::vec4(1, 1, 1, 1)));

	Timer time;
	float timer = 0;
	unsigned int frames = 0;
	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.f - 16.0f), (float)(9.0f - y * 18.0f / 540.f)));
		shader2.enable();
		//shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.f - 13.0f), (float)(9.0f - y * 18.0f / 540.f)));

		layer.render();
		//layer2.render();

		window.update();
		frames++;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
	}

	return 0;
}
