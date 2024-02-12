#pragma once
#include "componentarray.h"
namespace Engine
{
	class PositionManager : IComponentArray
	{
		void deleteComponent(Entity e) override
		{

		}

		void update() override
		{

		}

		~PositionManager() override = 0;
	};
}