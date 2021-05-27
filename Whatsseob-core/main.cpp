#include "src/graphics/window.h"
#include "src//maths/maths.h"

int main(void)
{
	using namespace whatsseob;
	using namespace graphics;
	using namespace maths;

	Window window("HelloSeob!", 800, 600);
	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mat4 position = mat4::translation(vec3(2, 3, 4));
	position *= mat4::identity();
	while (!window.closed())
	{
		window.clear();
		
		//if (window.isMouseButtonPressed(GLFW_MOUSE_BUTTON_LEFT)) //window.isKeyPressed(GLFW_KEY_A)
		
#if 1
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);		
#endif
		window.update();
	}

	system("PAUSE");
	return 0;
}
