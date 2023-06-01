#include <iostream>
#include "src/global/instances.h"

#include "src/global/functions.h"
#include <map>
#include <unordered_map>
#include <src/camera/camera.h>
#include <src/core/app.h>

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

	App* app = new App();
	app->init();
	
	
	glfwSetKeyCallback(app->getWindow(), key_callback);
	glfwSetCursorPosCallback(app->getWindow(), cursor_position_callback);
	glfwSetMouseButtonCallback(app->getWindow(), mouse_button_callback);

	

	

	double frameStart = 0;
	double length = 0;
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