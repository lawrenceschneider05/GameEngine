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
		glm::vec2 cords = camera->convertScreenToWorldCoordinates(inputManager->getMousePos());
		renderer->drawQuad(cords.x, cords.y, 1000, 100, Engine::Colors::RED);
		renderer->drawQuad(0, 0, 100, 100, Engine::Colors::BLUE);

	}
}