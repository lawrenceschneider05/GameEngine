#include "entitymanager.h"
#include "collision/collisionmanager.h"

namespace Engine
{
	EntityManager::EntityManager()
	{
		for (EntityID id = 0; id < MAX_ENTITES; id++)
		{
			freeIDs.push(id);
		}
	}

	EntityManager::~EntityManager()
	{
		for (auto const& e : entityMap)
		{
			delete e.second;
		}
	}

	void EntityManager::input()
	{
		for (auto const& e : entityMap)
		{
			e.second->input();
		}
	}

	void EntityManager::update(long double dt)
	{
		for (auto const& e : entityMap)
		{
			e.second->update(dt);
		}
	}

	void EntityManager::render()
	{
		for (auto const& e : entityMap)
		{
			e.second->render();
		}
	}

	void EntityManager::collisions()
	{
		std::vector<IEntity*> entities{};

		typedef std::map<EntityID, IEntity*> map;

		for (map::const_iterator it = entityMap.begin(); it != entityMap.end(); ++it) {
			entities.push_back(it->second);
		}

		CollisionManager::findCollisions(entities);
	}
}