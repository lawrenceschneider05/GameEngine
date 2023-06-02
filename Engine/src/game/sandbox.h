#pragma once
#include "global/instances.h"
#include "global/functions.h"
using namespace Engine::Global;
namespace Game
{
	class Sandbox
	{
	public:
		Sandbox();
		~Sandbox();

		void input();
		void update(long double dt);
		void render();
	private:
	};
}