#include <iostream>
#include "window/window.h"
#include "global/instances.h"
#include "global/functions.h"
#include <map>
#include <unordered_map>

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

	while (!window.shouldClose())
	{
		glfwPollEvents();

		window.clear(0.2125f, 0.4356f, 0.85f, 1.f);
		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}
		if (input.isLeftMousePressed())
		{
			window.close();
		}
		std::cout << input.getMousePos().x << "\n";
		window.swapBuffers();
	}
}