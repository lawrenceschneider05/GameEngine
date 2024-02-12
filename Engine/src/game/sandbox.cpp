#include "sandbox.h"
#include <vector>
using namespace std;
using namespace Engine::Global;
namespace Game
{
	glm::vec2 player{0,0};
	glm::vec2 player2{ 100,100 };
	bool up = 0, down = 0, left = 0, right = 0;
	
	Sandbox::Sandbox()
	{
		//camera->cameraMove = 0;
	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::input()
	{
		if (inputManager->keyDown(KEY_UP))
		{
			up = true;
			down = false;
		}
		else if (inputManager->keyDown(KEY_DOWN))
		{
			down = true;
			up = false;
		}
		else
		{
			down = false;
			up = false;
		}
		if (inputManager->keyDown(KEY_LEFT))
		{
			left = true;
			right = false;
		}
		else if (inputManager->keyDown(KEY_RIGHT))
		{
			right = true;
			left = false;
		}
		else
		{
			right = false;
			left = false;
		}
	}

	void Sandbox::update(long double dt)
	{
		if (up)
		{
			if (player.y + 150 * dt <= window->getWindowSize().y)
			{
				player.y += 500 * dt;
			}
		}
		if (down)
		{
			if (player.y >= 0)
			{
				player.y -= 500 * dt;
			}
		}
		if (left)
		{
			if (player.x >= 0)
			{
				player.x -= 500 * dt;
			}
		}
		if (right)
		{
			if (player.x + 150 * dt <= window->getWindowSize().x)
			{
				player.x += 500 * dt;
			}
		}
		player2 = camera->convertScreenToWorldCoordinates(inputManager->getMousePos());
	}

	void Sandbox::render()
	{
		renderer->drawQuad(player.x, player.y, 150, 150, Engine::Colors::BLUE);
		renderer->drawQuad(player2.x, player2.y, 150, 150, Engine::Colors::RED);
	}
}