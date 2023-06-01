#pragma once
#include "global/instances.h"
using namespace Engine::Global;
namespace Game
{
	class Sandbox
	{
	public:
		Sandbox();
		~Sandbox();

		void input();
		void update();
		void render();
	private:
	};
}