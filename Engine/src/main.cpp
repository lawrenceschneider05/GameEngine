#include <iostream>
#include "global/instances.h"

#include "global/functions.h"
#include <map>
#include <unordered_map>
#include <src/camera/camera.h>

using namespace Engine;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Global::input->keyPressed(key);
	}
	else if (action == GLFW_RELEASE)
	{
		Global::input->keyReleased(key);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Global::input->mouseMoved(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			Global::input->leftMousePressed();
		}
		else {
			Global::input->leftMouseReleased();
		}
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
		{
			Global::input->rightMousePressed();
		}
		else {
			Global::input->rightMouseReleased();
		}
	}
}

int main(int argc, char** argv)
{
	float a = 0;
	std::cout << "Hello Game Engine!\n";

	Global::initGLFW();

	Window window = Window("Engine");
	Global::window = &window;
	window.init();

	InputManager input = InputManager();
	Global::input = &input;
	
	Global::initGLAD();
	Global::setUpGL();
	
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	Renderer renderer = Renderer();
	Global::renderer = &renderer;
	renderer.init();

	Camera camera;
	camera.init(window.getWindowSize().x, window.getWindowSize().y);

	double frameStart = 0;
	double length = 0;
	double FPS = 30;
	//glfwSwapInterval(1);
	while (!window.shouldClose())
	{

		frameStart = glfwGetTime();
		glfwPollEvents();

		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}
		camera.update(input);
		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}
		if (input.keyDown(KEY_ESCAPE))
		{
			camera.setScale(camera.getScale() + 1);
		}
		int w, h;
		glfwGetWindowSize(window, &w, &h);
		camera.init(w, h);

			window.clear(0.2125f, 0.4356f, 0.85f, 1.f);

			renderer.beginFrame();
			GLint loc = renderer.getBatchShader().getUniformLocation("P");
			glm::mat4 camMatrix = camera.getOrthoMatrix();
			glUniformMatrix4fv(loc, 1, GL_FALSE, &(camMatrix[0][0]));

			for (int y = 0; y < 32; y++)
			{
				for (int x = 0; x < 32; x++)
				{
					renderer.drawQuad(x * 32, y * 32, 32, 32, (x / 32.0f) * 255.0f, (y / 32.0f) * 255.0f, x * y / 255.0f, 1.0f);
				}
			}
		

		renderer.endFrame();
		window.swapBuffers();

		length = glfwGetTime() - frameStart;
		while (length < 1.0 / FPS)
		{
			length = glfwGetTime() - frameStart;
		}
		
		window.setTitle(std::to_string((1.0f / (glfwGetTime() - frameStart))));
	}
}