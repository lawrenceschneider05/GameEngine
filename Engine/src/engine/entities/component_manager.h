#pragma once
#include <array>
#include <entities/entities.h>
#include "transform_component.h"
#include <iostream>

namespace Engine
{
	class ComponentManager
	{
	public:
		ComponentManager()
		{

		}
		~ComponentManager()
		{
			for (Transform* t : transform_array)
			{
				delete t;
			}
		}
		void addTransform(EntityID id, Transform* t)
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
				std::cout << "ComponentManager: tried to add a component to an invalid entity\n";
			}
			transform_array[id] = t;
		}

		Transform* getTransform(EntityID id)
		{
			try
			{
				if (id < 0 || id > MAX_ENTITIES || transform_array[id] == NULL)
				{
					throw;
				}
				
			}
			catch (EntityID id)
			{
				std::cout << "ComponentManager: tried to get a component from an invalid entity\n";
			}
			return transform_array[id];
		}

		void removeTransform(EntityID id)
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
			delete transform_array[id];
			transform_array[id] = 0;
		}
		
	private:
		std::array<Transform*, MAX_ENTITIES> transform_array{};
	};
}