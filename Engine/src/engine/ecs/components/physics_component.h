#pragma once
#include "component.h"
#include "glm/glm.hpp"
namespace Engine
{
	struct PhysicsComponent : public Component
	{
		glm::vec2 position;
		glm::vec2 velocity;
		glm::vec2 acceleration;
		bool gravityOn = false;

		PhysicsComponent(glm::vec2 position, glm::vec2 velocity, glm::vec2 acceleration)
		{
			this->position = position;
			this->velocity = velocity;
			this->acceleration = acceleration;
		}

		ComponentType getComponentType() override
		{
			return PHYSICS_COMPONENT;
		}
	};
}