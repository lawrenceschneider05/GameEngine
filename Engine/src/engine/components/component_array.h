#pragma once
#include <array>
#include <entities/entities.h>
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
			for (Component* t : component_array)
			{
				delete t;
			}
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
			component_array[id] = c;
		}

		Component* getComponent(EntityID id)
		{
			try
			{
				if (id < 0 || id > MAX_ENTITIES || component_array[id] == NULL)
				{
					throw;
				}
				
			}
			catch (EntityID id)
			{
				std::cout << "ComponentManager: tried to get a component from an invalid entity\n";
			}
			return component_array[id];
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
			delete component_array[id];
			component_array[id] = 0;
		}
		
	private:
		std::array<Component*, MAX_ENTITIES> component_array{};
		ComponentType component_type;
	};
}