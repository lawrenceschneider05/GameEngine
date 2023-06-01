#include "sandbox.h"
namespace Game
{
	Sandbox::Sandbox()
	{

	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::input()
	{
		
	}

	void Sandbox::update()
	{

	}

	void Sandbox::render()
	{
		renderer->drawQuad(100, 100, 100, 100, Engine::Colors::RED);
	}
}