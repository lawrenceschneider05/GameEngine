#pragma once
#include <ecs/entity.h>
#include <array>
namespace Engine
{
	class EntityManager
	{
	public:
		EntityManager(Entity maxEntities);
		~EntityManager();

		Entity getMaxEntites() { return maxEntities; }
		Entity getNumEntities() { return numEntities;  }
	private:
		const Entity maxEntities;
		Entity numEntities;
	};
}