#pragma once
#include "ecs/components/component.h"

namespace Engine
{
	struct IScriptComponent : public Component
	{
		
		virtual void run(long double dt) = 0;
	};
}