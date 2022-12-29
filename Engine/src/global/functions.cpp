#include "functions.h"
#include <glad/glad.h>
#include <vendor/include/GLFW/glfw3.h>
#include <iostream>

namespace Engine
{
	namespace Global
	{
		void initGLFW()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_SAMPLES, 32);
		}

		void initGLAD()
		{
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to initialize OpenGL.";
			}
		}
	}
}