#pragma once
#include "global/instances.h"
#include "global/functions.h"
#include <src/game/sandbox.h>

namespace Engine
{
	class App
	{
	public:
		App();
		~App();

		void init();

		void input();

		void render();

		void update();

		Window& getWindow()
		{
			return *window;
		}

		InputManager& getInput()
		{
			return *im;
		}

		Renderer& getRenderer()
		{
			return *renderer;
		}
	private:
		Window* window;
		InputManager* im;
		Renderer* renderer;
		Camera* camera;

		Game::Sandbox* game;
	};
}