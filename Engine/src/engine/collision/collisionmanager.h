#pragma once
#include <vector>
#include <entities/ientity.h>
#include <collision/Quad.h>
#include "CollisionFinder.h"

namespace Engine
{
	class CollisionManager
	{
	public:
		static void findCollisions(std::vector<IEntity*> entities)
		{
			for (int i = 0; i < entities.size(); i++)
			{
				for (int j = i+1; j < entities.size(); j++)
				{
					IEntity* e1 = entities.at(i);
					IEntity* e2 = entities.at(j);
					Quad q1 = e1->getQuad();
					Quad q2 = e2->getQuad();
					if (CollisionFinder::AABB(q1, q2) == true)
					{
						//std::cout << q1.x << " " << q2.x << "\n";
						e1->collisionWith(e2);
						e2->collisionWith(e1);
						//std::cout << "a";
					}
					
					
				}
			}
		}
	private:
	};
}