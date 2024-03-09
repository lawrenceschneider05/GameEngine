#pragma once
#include <ecs/components/component_array.h>
namespace Engine
{
	class ISystem
	{
	public:
		virtual ~ISystem() = default;
		virtual void run(long double dt) = 0;
	protected:
		ComponentArray* comp_array;
	};
}