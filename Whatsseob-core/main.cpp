#include "src/graphics/window.h"

int main(void)
{
	using namespace whatsseob;
	using namespace graphics;

	Window window("HelloSeob!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);


	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glEnd();
		
		window.update();
	}

	system("PAUSE");
	return 0;
}
