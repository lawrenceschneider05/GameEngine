#pragma once
#include <GLFW/glfw3.h>
#include <string>

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

		void close()
		{
			glfwSetWindowShouldClose(window, true);
		}

		bool shouldClose()
		{
			return glfwWindowShouldClose(window);
		}
	private:
		GLFWwindow* window;
		std::string title;
	};
}