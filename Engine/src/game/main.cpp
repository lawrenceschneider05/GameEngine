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
		Global::inputManager->keyPressed(key);
	}
	else if (action == GLFW_RELEASE)
	{
		Global::inputManager->keyReleased(key);
	}
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	Global::inputManager->mouseMoved(xpos, ypos);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			Global::inputManager->leftMousePressed();
		}
		else {
			Global::inputManager->leftMouseReleased();
		}
	}
	if (button == GLFW_MOUSE_BUTTON_RIGHT)
	{
		if (action == GLFW_PRESS)
		{
			Global::inputManager->rightMousePressed();
		}
		else {
			Global::inputManager->rightMouseReleased();
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






	double FPS = 500;
	//glfwSwapInterval(1);

	double lastRender = -FPS;
	while (!app->getWindow().shouldClose())
	{


		app->input();



		app->update();

		if (glfwGetTime() - lastRender > 1 / FPS)
		{
			//std::cout << (glfwGetTime() - lastRender) << "\n";
			app->getWindow().setTitle(std::to_string((1.0f / (glfwGetTime() - lastRender))));
			app->render();

			
			
			lastRender = glfwGetTime();
			

		}
		
	}
	delete app;
}