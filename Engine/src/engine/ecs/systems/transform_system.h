#pragma once
#include "isystem.h"
#include <ecs/components/physics_component.h>
namespace Engine
{
	class TransformSystem : public ISystem
	{
	public:
		TransformSystem(ComponentArray* comp_array, ComponentArray* physics_comp_array)
		{
			this->comp_array = comp_array;
			this->physics_comp_array = physics_comp_array;
		}

		void run(long double dt) override
		{
			for (int i = 0; i < physics_comp_array->getComponentArray()->size(); i++)
			{
				if (comp_array->getComponentArray()->at(i) != NULL)
				{
					TransformComponent* t = (TransformComponent*)comp_array->getComponentArray()->at(i);
					if (i < physics_comp_array->getComponentArray()->size())
					{
						if (physics_comp_array->getComponentArray()->at(i) != NULL)
						{
							PhysicsComponent* p = (PhysicsComponent*)physics_comp_array->getComponentArray()->at(i);
							t->position = p->position;
							std::cout << t->position.x << "c\n";
						}
					}
					
				}
			}
		}
	private:
		ComponentArray* physics_comp_array;
	};
}