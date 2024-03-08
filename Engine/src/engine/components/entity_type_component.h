#pragma once
#include "glm/glm.hpp"
#include "component.h"
namespace Engine
{
	enum EntityType
	{
		ENTITY_PLAYER
	};
	struct EntityTypeComponent : public Component
	{
		EntityType type;

		EntityTypeComponent(EntityType type)
		{
			this->type = type;
		}

		ComponentType getComponentType() override
		{
			return ENTITY_TYPE_COMPONENT;
		}
	};
}