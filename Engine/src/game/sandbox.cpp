#include "sandbox.h"
namespace Game
{
	Sandbox::Sandbox()
	{
		camera->cameraMove = 1;
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
		renderer->drawQuad(inputManager->getMousePos().x, inputManager->getMousePos().y, 1000, 100, Engine::Colors::RED);

	}
}