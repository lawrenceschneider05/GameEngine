#pragma once
#include "global/instances.h"
#include "global/functions.h"
#include <src/game/sandbox.h>
#include <ecs/components/component_manager.h>
#include <ecs/ecs.h>

namespace Engine
{
	class App
	{
	public:
		App();
		~App();

		void init();

		void input(long double dt);

		void render(long double dt);

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
		ECS* ecs;

		Game::Sandbox* game;
		
	};
}