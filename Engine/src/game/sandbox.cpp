#include "sandbox.h"
#include <vector>
using namespace std;
namespace Game
{
	vector<glm::vec2> points;
	
	Sandbox::Sandbox()
	{
		camera->cameraMove = 1;
	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::input()
	{
		if (inputManager->isLeftMousePressed())
		{
			points.push_back(getMousePos());
		}
	}

	void Sandbox::update()
	{

	}

	void Sandbox::render()
	{
		renderer->drawQuad(getMousePos().x, getMousePos().y, 1000, 100, Engine::Colors::RED);
		renderer->drawQuad(0, 0, 100, 100, Engine::Colors::BLUE);
		for (int i = 0; i < points.size(); i++)
		{
			renderer->drawQuad(points[i].x, points[i].y, 10, 10, Engine::Colors::BLUE);
		}
	}
}