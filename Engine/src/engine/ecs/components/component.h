#pragma once
namespace Engine
{
	enum ComponentType
	{
		TRANSFORM_COMPONENT = 0,
		ENTITY_TYPE_COMPONENT = 1,
		PHYSICS_COMPONENT = 2
	};
	struct Component
	{
		virtual ComponentType getComponentType() = 0;
	};
}