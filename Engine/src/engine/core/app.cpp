#include "app.h"
#include "GLFW/glfw3.h"

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
		delete em;

		delete game;
	}
	void App::init()
	{
		window = new Window("Engine");
		Global::window = &*window;
		window->init();

		im = new InputManager(window);
		Global::inputManager = &*im;

		Global::initGLAD();
		Global::setUpGL();

		renderer = new Renderer();
		Global::renderer = &*renderer;
		renderer->init();

		camera = new Camera();
		camera->init(window->getWindowSize().x, window->getWindowSize().y);
		Global::camera = &*camera;

		em = new EntityManager();
		Global::entityManager = em;

		game = new Game::Sandbox();
		glfwSwapInterval(1);
	}

	void App::input()
	{
		glfwPollEvents();

		if (im->keyDown(KEY_ESCAPE))
		{
			window->close();
		}
		em->input();
		game->input();
	}

	void App::render()
	{
		window->clear(0.2125f, 0.4356f, 0.85f, 1.f);

		renderer->beginFrame();

		GLint loc = renderer->getBatchShader().getUniformLocation("P");
		glm::mat4 camMatrix = camera->getOrthoMatrix();
		glUniformMatrix4fv(loc, 1, GL_FALSE, &(camMatrix[0][0]));
		em->render();
		game->render();

		renderer->endFrame();

		window->swapBuffers();
	}

	void App::update(long double dt)
	{
		int w, h;
		glfwGetWindowSize(*window, &w, &h);
		camera->init(w, h);
		camera->update(*im, dt);
		
		//window->setTitle(std::to_string(renderer->quadCount()));
		em->update(dt);
		game->update(dt);
	}
}