#pragma once
#include "global/instances.h"
#include "global/functions.h"
#include <src/game/sandbox.h>
#include <components/component_manager.h>
#include <entities/entity_manager.h>

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

		void update(long double dt);

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
		EntityManager* em;
		ComponentManager* cm;

		Game::Sandbox* game;
		
	};
}