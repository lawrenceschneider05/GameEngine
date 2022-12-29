#include <iostream>
#include <glad/glad.h>
#include <vendor/include/GLFW/glfw3.h>
#include "window/window.h"
#include "global/global.h"


using namespace Engine;
int main(int argc, char** argv)
{
	std::cout << "Hello Game Engine!\n";

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 32);

	Window window = Window("Engine");
	Global::window = &window;
	window.init();
	
	

	



	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL.";
	}

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