#include "player.h"
#include "global/functions.h"
#include "global/instances.h"
using namespace Engine::Global;
namespace Engine
{
	Player::Player(glm::vec2 position, glm::vec2 size, Color c, EntityType type)
	{
		this->position = position;
		this->size = size;
		color = c;
		this->TYPE = type;
	}

	Player::~Player()
	{

	}
	void Player::input()
	{
		position = getMousePos();
		
	}

	void Player::update(long double dt)
	{

		if (keyDown(KEY_UP))
		{
			size += 100.f * dt;
		}
		else if (keyDown(KEY_DOWN))
		{
			size -= 100.f * dt;
		}
	}


	void Player::render()
	{
		Global::renderer->drawQuad(position, size, color);
		color = Colors::BLACK;
	}

	void Player::collisionWith(IEntity* e)
	{
		
		if (e->TYPE == WALL)
		{
			color = Colors::RED;
		}
	}
}