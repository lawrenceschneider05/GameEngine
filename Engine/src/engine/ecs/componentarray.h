#pragma once
#include <ecs/entity.h>
namespace Engine
{
	class IComponentArray
	{
		virtual void deleteComponent(Entity e);
		virtual void update();
		virtual ~IComponentArray();
	};
}