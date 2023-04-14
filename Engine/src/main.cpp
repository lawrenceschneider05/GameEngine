#include <iostream>
#include "global/instances.h"

#include "global/functions.h"
#include <map>
#include <unordered_map>

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

	Window window = Window("Engine");
	Global::window = &window;
	window.init();

	InputManager input = InputManager();
	Global::input = &input;
	
	Global::initGLAD();
	Global::setUpGL();
	
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	Renderer renderer = Renderer();
	Global::renderer = &renderer;
	renderer.init();


	Camera camera(Global::window->getWindowSize().x, Global::window->getWindowSize().y, glm::vec3(0.0f, 0.0f, 2.0f));
	camera.Position.z = 10;
	Global::camera = &camera;
	//camera.init(window.getWindowSize().x, window.getWindowSize().y);
	
	//GLint pLocation = renderer.getBatchShader().getUniformLocation("camMatrix");
	//std::cout << pLocation;
	//glm::mat4 cameraMatrix = camera.getCameraMatrix();
	//std::cout << cameraMatrix[1][1];

	//glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));

	while (!window.shouldClose())
	{
		glfwPollEvents();

		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}

		window.clear(0.2125f, 0.4356f, 0.85f, 1.f);
		camera.Inputs(window);
		camera.Matrix(45.0f, 0.1f, 1000.0f, renderer.getBatchShader(), "camMatrix");
		renderer.beginFrame();


		//renderer.drawQuad(2 * (input.getMousePos().x / 800) - 1, -(2 * (input.getMousePos().y / 640) - 1), 0.5f, 0.5f, 1.0f, 1.0f, 0.5f, a);
		//std::cout << -(2 * (input.getMousePos().y / window.getWindowSize().y) - 1) << "\n";
		renderer.drawQuad(-10, -10, 200, 200, 1.0f, 1.0f, 1.0f, 1.0f);
		renderer.drawQuad(a, 0, 100, 100, 1, 1, 1, 1);

		if (input.keyDown(KEY_W))
		{
			a += 0.01f;
		}
		if (input.keyDown(KEY_S))
		{
			a -= 0.01f;
		}
		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}
		
		glfwGetWindowSize(window, &camera.width, &camera.height);
		renderer.endFrame();
		window.swapBuffers();
	}
}