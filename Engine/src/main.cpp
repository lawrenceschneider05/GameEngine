#include <iostream>


#include "window/window.h"
#include "global/instances.h"
#include "global/functions.h"

using namespace Engine;
int main(int argc, char** argv)
{
	std::cout << "Hello Game Engine!\n";

	
	Global::initGLFW();
	
	Window window = Window("Engine");
	Global::window = &window;
	window.init();
	
	Global::initGLAD();

	
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	


	


	while (!window.shouldClose())
	{
		glfwPollEvents();

		if (glfwGetKey((window), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			window.close();
		}

		window.swapBuffers();
	}

	//delete Global::window;
}