#include "app.h"

namespace Engine
{
	App::App()
	{
		
	}

	App::~App()
	{
		delete window;
		delete im;
		delete renderer;
		delete camera;

		delete game;
	}
	void App::init()
	{
		window = new Window("Engine");
		Global::window = &*window;
		window->init();

		im = new InputManager();
		Global::input = &*im;

		Global::initGLAD();
		Global::setUpGL();

		renderer = new Renderer();
		Global::renderer = &*renderer;
		renderer->init();

		camera = new Camera();
		camera->init(window->getWindowSize().x, window->getWindowSize().y);

		game = new Game::Sandbox();
	}

	void App::input()
	{
		glfwPollEvents();

		if (im->keyDown(KEY_ESCAPE))
		{
			window->close();
		}
		
		game->input();
	}

	void App::render()
	{
		window->clear(0.2125f, 0.4356f, 0.85f, 1.f);

		renderer->beginFrame();

		GLint loc = renderer->getBatchShader().getUniformLocation("P");
		glm::mat4 camMatrix = camera->getOrthoMatrix();
		glUniformMatrix4fv(loc, 1, GL_FALSE, &(camMatrix[0][0]));

		game->render();


		renderer->endFrame();

		window->swapBuffers();
	}

	void App::update()
	{
		int w, h;
		glfwGetWindowSize(*window, &w, &h);
		camera->init(w, h);
		camera->update(*im);
		
		game->update();
	}
}