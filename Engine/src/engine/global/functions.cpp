#include "functions.h"
#include <glad/glad.h>
#include <vendor/include/GLFW/glfw3.h>
#include <iostream>
#include <vendor/include/glm/fwd.hpp>
#include "instances.h"
#include <input/InputManager.h>

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

		void setUpGL()
		{
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}

		glm::vec2 getMousePos()
		{
			return camera->convertScreenToWorldCoordinates(input_manager->getMousePos());
		}

		bool keyDown(int key)
		{
			return input_manager->keyDown(key);
		}
	}
}