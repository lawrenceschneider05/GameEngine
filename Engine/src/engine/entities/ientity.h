#pragma once
#include "glm/glm.hpp"
#include <renderer/colors.h>
#include <iostream>
#include <entities/entitytypes.h>
#include <collision/Quad.h>

namespace Engine
{
	class IEntity
	{
	public:
		EntityType TYPE;
		IEntity()
		{

		}
		virtual ~IEntity()
		{

		}

		virtual void input()
		{

		}

		virtual void update(long double dt)
		{
			std::cout << 3;
		}

		virtual void render()
		{

		}

		Quad getQuad()
		{
			return Quad(position, size);
		}
		virtual void collisionWith(IEntity* e)
		{
			//std::cout << 7;
		}
	protected:
		glm::vec2 position{}, size{};
	};
}