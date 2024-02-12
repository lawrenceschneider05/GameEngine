#include "wall.h"
#include "global/instances.h"
namespace Engine
{
	Wall::Wall(glm::vec2 position, glm::vec2 size, Color c, EntityType type)
	{
		this->position = position;
		this->size = size;
		this->color = color;
		this->TYPE = type;
	}

	Wall::~Wall()
	{

	}

	void Wall::input()
	{

	}

	void Wall::update(long double dt)
	{

	}

	void Wall::render()
	{
		Global::renderer->drawQuad(position, size, color);
	}

	void Wall::collisionWith(IEntity* e)
	{

	}
}