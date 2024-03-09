#pragma once
#include "isystem.h"
#include <renderer/renderer.h>

namespace Engine
{
	class RenderSystem : public ISystem
	{
	public:
		RenderSystem(ComponentArray* comp_array, Renderer* renderer)
		{
			this->comp_array = comp_array;
			this->renderer = renderer;
		}
		~RenderSystem() override
		{
			// calls an exception
			//delete comp_array;
		}

		void run(long double dt) override
		{
			for (auto it = comp_array->getComponentArray()->begin(); it < comp_array->getComponentArray()->end(); it++)
			{
				if (*it != NULL)
				{
					renderer->drawQuad(*(TransformComponent*)*it, Colors::RED);
				}
			}
		}
	private:
		ComponentArray* comp_array;
		Renderer* renderer;
	};
}