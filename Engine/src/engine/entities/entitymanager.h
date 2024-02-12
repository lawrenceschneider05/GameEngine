#pragma once
#include <map>
#include <entities/ientity.h>
#include <iostream>
#include <stdexcept>
#include <queue>
namespace Engine
{
	using EntityID = unsigned int;
	const EntityID MAX_ENTITES = 128;

	class EntityManager
	{
	public:
		EntityManager();

		~EntityManager();

		inline EntityID addEntity(IEntity* entity)
		{
			EntityID id = freeIDs.front();
			freeIDs.pop();

			entityMap.emplace(id, entity);

			return id;
		}

		void input();
		void update(long double dt);
		void render();

		inline void removeEntity(EntityID id)
		{
			try
			{
				if (entityExists(id))
				{
					entityMap.erase(id);
				}
				else
				{
					throw id;
				}
			}
			catch (EntityID id)
			{
				std::cout << "ERROR: Tried to remove nonexistant entity id: " << id <<"\n";
			}
		}

		inline bool entityExists(EntityID id)
		{
			return entityMap.count(id);
		}

		inline EntityID totalEntities() { return entityMap.size(); }

	private:
		std::map<EntityID, IEntity*> entityMap{};
		std::queue<EntityID> freeIDs{};
	};
}