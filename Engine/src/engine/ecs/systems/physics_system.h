#pragma once
#include "isystem.h"
#include <ecs/components/physics_component.h>
namespace Engine
{
	class PhysicsSystem : public ISystem
	{
	public:
		PhysicsSystem(ComponentArray* comp_array)
		{
			this->comp_array = comp_array;
		}

		void run(long double dt) override
		{
			for (auto it = comp_array->getComponentArray()->begin(); it < comp_array->getComponentArray()->end(); it++)
			{
				if (*it != NULL)
				{
					PhysicsComponent* p = (PhysicsComponent*)*it;
					p->velocity.x += p->acceleration.x * dt;
					p->position.x += p->velocity.x * dt;
					std::cout << dt << "a\n";
				}
			}
		}
	private:
	};
}