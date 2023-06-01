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





	double frameStart = 0;
	double length = 0;

	// 37 currently highest stable fps at fullscreen with no quads :(
	double FPS = 30;
	//glfwSwapInterval(1);
	while (!app->getWindow().shouldClose())
	{

		frameStart = glfwGetTime();

		app->input();



		app->update();


		app->render();


		length = glfwGetTime() - frameStart;
		while (length < 1.0 / FPS)
		{
			length = glfwGetTime() - frameStart;
		}

		app->getWindow().setTitle(std::to_string((1.0f / (glfwGetTime() - frameStart))));


	}
	delete app;
}