#include <iostream>
#include "global/instances.h"
#include "global/functions.h"
#include <map>
#include <unordered_map>
#include <camera/camera.h>
#include <core/app.h>

using namespace Engine;


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS)
	{
		Global::input_manager->keyPressed(key);
	}
	else if (action == GLFW_RELEASE)
	{
		Global::input_manager->keyReleased(key);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Global::input_manager->mouseMoved(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			Global::input_manager->leftMousePressed();
		}
		else {
			Global::input_manager->leftMouseReleased();
		}
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
		{
			Global::input_manager->rightMousePressed();
		}
		else {
			Global::input_manager->rightMouseReleased();
		}
	}
}

int main(int argc, char** argv)
{


	float a = 0;
	std::cout << "Hello Game Engine!\n";

	Global::initGLFW();

	App* app = new App();
	app->init();


	glfwSetKeyCallback(app->getWindow(), key_callback);
	glfwSetCursorPosCallback(app->getWindow(), cursor_position_callback);
	glfwSetMouseButtonCallback(app->getWindow(), mouse_button_callback);






	double FPS = 60;
	//glfwSwapInterval(1);

	double lastRender = -FPS;
	double frameStart = 0;
	long double dt = 0;
	while (!app->getWindow().shouldClose())
	{
		frameStart = glfwGetTime();

		app->input(dt);

		app->update(dt);

		if ((glfwGetTime() - lastRender > 1 / FPS))
		{
			app->getWindow().setTitle(std::to_string((1.0f / (glfwGetTime() - lastRender))));
			app->render((glfwGetTime() - lastRender));
			
			lastRender = glfwGetTime();
			

		}
		dt = glfwGetTime() - frameStart;
		//std::cout << 1.0f / dt << "\n";
	}
	delete app;
}