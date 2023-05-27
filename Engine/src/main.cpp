#include <iostream>
#include "global/instances.h"

#include "global/functions.h"
#include <map>
#include <unordered_map>
#include <src/camera/c.h>

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

	C camera;
	camera.init(window.getWindowSize().x, window.getWindowSize().y);

	//Camera camera(Global::window->getWindowSize().x, Global::window->getWindowSize().y, glm::vec3(0.0f, 0.0f, 2.0f));
	//camera.Position.z = 10;
	//Global::camera = &camera;
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
		camera.update();
		

		window.clear(0.2125f, 0.4356f, 0.85f, 1.f);
		//camera.Inputs(window);
		//camera.Matrix(45.0f, 0.1f, 1000.0f, renderer.getBatchShader(), "camMatrix");
		renderer.beginFrame();
		GLint loc = renderer.getBatchShader().getUniformLocation("P");
		glm::mat4 camMatrix = camera.getOrthoMatrix();
		glUniformMatrix4fv(loc, 1, GL_FALSE, &(camMatrix[0][0]));

		renderer.drawQuad(input.getMousePos().x, window.getWindowSize().y - input.getMousePos().y, 100, 100, 1, 1, 1, 1);
		//renderer.drawQuad(10*(input.getMousePos().x / window.getWindowSize().x), -(input.getMousePos().y / window.getWindowSize().y), 10, 10, 1, 1, 1, 1);
		
		//renderer.drawQuad(camera.screenToWorldCords(input.getMousePos()).x, camera.screenToWorldCords(input.getMousePos()).y, 10, 10, 1, 1, 1, 1);

		std::cout << input.getMousePos().x << "  " << input.getMousePos().y << "\n";
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
		
		//glfwGetWindowSize(window, &camera.width, &camera.height);

		renderer.endFrame();
		window.swapBuffers();
	}
}