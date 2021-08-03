#include "../src/whatsseob.h"

using namespace whatsseob;
using namespace graphics;

class Game : public Whatsseob
{
private:
	Window* window;
	Layer* layer;
	Sprite* sprite;
	Shader* shader;
public :
	Game()
	{

	}

	~Game()
	{
		delete layer;
	}

	void init() override
	{
		window = createWindow("test game", 960, 540);
		shader = new Shader("src/shaders/basic.vert", "src/shaders/basic.frag");
		layer = new Layer(new BatchRenderer2D(), shader, maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));
		sprite = (new Sprite(0.0f, 0.0f, 4, 4, new Texture("test.png")));
		layer->add(sprite);
	}

	void tick() override
	{
		std::cout << getUPS() << " ups, " << getFPS() << " fps" << std::endl;
	}

	void update() override
	{
		float speed = 0.5f;
		if (window->isKeyPressed(GLFW_KEY_UP))
			sprite->position.y += speed;
		else if (window->isKeyPressed(GLFW_KEY_DOWN))
			sprite->position.y -= speed;
		if (window->isKeyPressed(GLFW_KEY_LEFT))
			sprite->position.x -= speed;
		else if (window->isKeyPressed(GLFW_KEY_RIGHT))
			sprite->position.x += speed;

		double x, y;
		window->getMousePosition(x, y);
		shader->setUniform2f("light_pos", maths::vec2((float)(x * 32.0f / window->getWidth() - 16.0f), (float)(9.0f - y * 18.0f / window->getHeight())));
		
	}

	void render() override
	{
		layer->render();
	}
};

int main()
{
	Game game;
	game.start();
	return 0;
}