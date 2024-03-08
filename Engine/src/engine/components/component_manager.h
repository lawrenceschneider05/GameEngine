#pragma once
#include <map>
#include <string>
#include "component_array.h"

namespace Engine
{
	class ComponentManager
	{
	public:
		void registerComponentArray(ComponentType type)
		{
			component_array_map.emplace(type, ComponentArray(type));
		}
		Component* getComponent(EntityID entity, ComponentType type)
		{
			return component_array_map.at(type).getComponent(entity);
		}
		void removeComponent(EntityID entity, ComponentType type)
		{
			component_array_map.at(type).removeComponent(entity);
		}
		void addComponent(EntityID id, Component* c)
		{
			component_array_map.at(c->getComponentType()).addComponent(id, c);
		}
	private:
		std::map<ComponentType, ComponentArray> component_array_map;
	};
}