#pragma once
#include "glm/glm.hpp"
#include <renderer/colors.h>


namespace Engine
{
	class IEntity
	{
	public:
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

		}

		virtual void render()
		{

		}

	protected:
	};
}