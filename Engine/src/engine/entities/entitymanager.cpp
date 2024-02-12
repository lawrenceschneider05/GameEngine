#include "entitymanager.h"

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
}