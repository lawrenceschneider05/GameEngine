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
	Global::setUpGL();
	


	while (!window.shouldClose())
	{
		glfwPollEvents();

		if (glfwGetKey((window), GLFW_KEY_ESCAPE) == GLFW_PRESS)
		{
			window.close();
		}

		window.clear(0.2125f, 0.4356f, 0.85f, 1.f);

		window.swapBuffers();
	}
}