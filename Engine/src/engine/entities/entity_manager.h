#pragma once
#include <queue>
#include <iostream>
namespace Engine
{
	using EntityID = long unsigned int;
	const long unsigned int MAX_ENTITIES = 10;

	class EntityManager
	{
	public:
		EntityManager()
		{
			for (EntityID e = 0; e < MAX_ENTITIES; e++)
			{
				available_entity_ids.push(e);
			}
		}

		EntityID createEntity()
		{
			try
			{
				if (available_entity_ids.empty())
				{
					throw;
				}
				EntityID e = available_entity_ids.front();
				available_entity_ids.pop();
				entity_ids.push_back(e);
				return e;
			}
			catch (...)
			{
				std::cout << "EntityManager: tried to create entity, no available entitie left.\n";
			}
		}

		void destroyEntity(EntityID id)
		{
			try
			{
				auto i = std::find(entity_ids.begin(), entity_ids.end(), id);
				if (i == entity_ids.end())
				{
					throw;
				}
				entity_ids.erase(i);
				available_entity_ids.push(id);
			}
			catch (...)
			{
				std::cout << "EntityManager: tried to destroy non-existent entity.\n";
			}
		}
	private:
		std::queue<EntityID> available_entity_ids{};
		std::vector<EntityID> entity_ids{};
	};
}