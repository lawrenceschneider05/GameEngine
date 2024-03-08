#pragma once
#include "glm/glm.hpp"
#include "component.h"
namespace Engine
{
	struct TransformComponent : public Component
	{
		glm::vec2 position;
		glm::vec2 size;

		TransformComponent(glm::vec2 position, glm::vec2 size)
		{
			this->position = position;
			this->size = size;
		}

		ComponentType getComponentType() override
		{
			return TRANSFORM_COMPONENT;
		}
	};
}