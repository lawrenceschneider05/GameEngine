#pragma once
#include <collision/Quad.h>
namespace Engine
{
	class CollisionFinder
	{
	public:
		static bool AABB(Quad q1, Quad q2)
		{
			if (q1.x <= q2.x + q2.w 
				&& q1.x + q1.w >= q2.x
				&& q1.y <= q2.y + q2.h
				&& q1.y + q1.h >= q2.y)
			{
				return true;
			}
			return false;
		}
	};
}