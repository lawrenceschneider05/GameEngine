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
	double frameStart = 0;
	double length = 0;
	double FPS = 60;
	//glfwSwapInterval(1);
	while (!window.shouldClose())
	{

		frameStart = glfwGetTime();
		glfwPollEvents();

		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}
		camera.update();
		if (input.keyDown(KEY_ESCAPE))
		{
			window.close();
		}
		if (input.keyDown(KEY_ESCAPE))
		{
			camera.setScale(camera.getScale() + 1);
		}
		int w, h;
		glfwGetWindowSize(window, &w, &h);
		camera.init(w, h);

		if (length < 1.0 / FPS)
		{
			window.clear(0.2125f, 0.4356f, 0.85f, 1.f);

			renderer.beginFrame();
			GLint loc = renderer.getBatchShader().getUniformLocation("P");
			glm::mat4 camMatrix = camera.getOrthoMatrix();
			glUniformMatrix4fv(loc, 1, GL_FALSE, &(camMatrix[0][0]));

			renderer.drawQuad(input.getMousePos().x - camera.getPosition().x, window.getWindowSize().y - input.getMousePos().y + camera.getPosition().y, 100, 100, 1, 1, 1, 1);
		}

		renderer.endFrame();
		window.swapBuffers();

		length = glfwGetTime() - frameStart;
		while (length < 1.0 / FPS)
		{
			length = glfwGetTime() - frameStart;
		}

		window.setTitle(std::to_string((1.0f / (glfwGetTime() - frameStart))));
	}
}