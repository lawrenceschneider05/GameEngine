#pragma once
#include <array>
#include <ecs/entities/entities.h>
#include "transform_component.h"
#include <iostream>

namespace Engine
{
	class ComponentArray
	{
	public:
		ComponentArray(ComponentType type)
		{
			this->component_type = type;
		}
		~ComponentArray()
		{
			// CATCHES AN EXCEPTION
			//for (EntityID e = 0; e < comp_array.size(); e++)
			//{
			//	if (comp_array[e] != NULL)
			//	{
			//		delete comp_array[e];
			//	}

			//}
		}
		void addComponent(EntityID id, Component* c)
		{
			try
			{
				if (id < 0 || id > MAX_ENTITIES || c->getComponentType() != component_type)
				{
					throw;
				}
			}
			catch (EntityID id)
			{
				std::cout << "ComponentManager: tried to add a component to an invalid entity\n";
			}
			comp_array[id] = c;
		}

		Component* getComponent(EntityID id)
		{
			try
			{
				if (id < 0 || id > MAX_ENTITIES || comp_array[id] == NULL)
				{
					throw;
				}
				
			}
			catch (EntityID id)
			{
				std::cout << "ComponentManager: tried to get a component from an invalid entity\n";
			}
			return comp_array[id];
		}

		void removeComponent(EntityID id)
		{
			try
			{
				if (id < 0 || id > MAX_ENTITIES)
				{
					throw;
				}

			}
			catch (EntityID id)
			{
				std::cout << "ComponentManager: tried to remove a component from an invalid entity\n";
			}
			delete comp_array[id];
			comp_array[id] = 0;
		}

		std::array<Component*, MAX_ENTITIES>* getComponentArray() { return &comp_array; }
		
	private:
		std::array<Component*, MAX_ENTITIES> comp_array{};
		ComponentType component_type;
	};
}