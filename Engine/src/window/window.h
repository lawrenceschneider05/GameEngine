#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include "glm/glm.hpp"

namespace Engine
{
	class Window
	{
	public:
		Window(std::string title);

		Window();

		~Window();

		bool init();

		operator GLFWwindow*()
		{
			return window;
		}

		void swapBuffers()
		{
			glfwSwapBuffers(window);
		}

		void clear(double r, double g, double b, double a)
		{
			glClearColor(r, g, b, a);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void close()
		{
			glfwSetWindowShouldClose(window, true);
		}

		bool shouldClose()
		{
			return glfwWindowShouldClose(window);
		}


		glm::vec2 getWindowSize() {
			int width, height;
			glfwGetWindowSize(window, &width, &height);
			glm::vec2 vec = { width, height };
			return vec;
		}
	private:
		GLFWwindow* window;
		std::string title;
	};
}