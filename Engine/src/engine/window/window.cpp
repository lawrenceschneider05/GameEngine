#include "window.h"
namespace Engine
{
	void framebuffer_size_callback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}
	Window::Window()
	{
		title = "Application";
	}

	Window::Window(std::string title)
	{
		this->title = title;
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}

	bool Window::init()
	{
		window = glfwCreateWindow(800, 640, title.c_str(), NULL, NULL);
		if (window == NULL)
		{
			return false;
		}
		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
		glfwSwapInterval(1);
		//glfwMaximizeWindow(window);
		return true;
	}
}