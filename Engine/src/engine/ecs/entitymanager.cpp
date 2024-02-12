#include "entitymanager.h"
namespace Engine
{
	EntityManager::EntityManager(Entity maxEntities) : maxEntities(maxEntities), numEntities(0)
	{
		
	}

	EntityManager::~EntityManager()
	{

	}
}