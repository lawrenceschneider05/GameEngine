#pragma once
#include <GLFW/glfw3.h>
#include <string>
#include <src/types/types.h>

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

		void clear(f64 r, f64 g, f64 b, f64 a)
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
	private:
		GLFWwindow* window;
		std::string title;
	};
}