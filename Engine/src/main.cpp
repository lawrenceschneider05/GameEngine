#include <iostream>
#include "window/window.h"
#include "global/instances.h"
#include "global/functions.h"
#include <map>
#include <unordered_map>

using namespace Engine;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE)
	{
		if (action == GLFW_PRESS)
		{
			Global::window->close();
		}
	}

	if (action == GLFW_PRESS)
	{
		Global::input->keyPressed(key);
	}
	else if (action == GLFW_RELEASE)
	{
		Global::input->keyReleased(key);
	}
}

int main(int argc, char** argv)
{
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

	while (!window.shouldClose())
	{
		glfwPollEvents();

		window.clear(0.2125f, 0.4356f, 0.85f, 1.f);
		if (input.keyDown(KEY_X))
		{
			window.close();
		}
		window.swapBuffers();
	}
}