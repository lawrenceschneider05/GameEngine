#include <glm/glm.hpp>
#pragma once
namespace Engine
{
	struct Quad
	{
		float x, y, w, h;

		Quad(float x, float y, float w, float h)
		{
			this->x = x;
			this->y = y;
			this->w = w;
			this->h = h;
		}

		Quad(glm::vec2 position, glm::vec2 size)
		{
			this->x = position.x;
			this->y = position.y;
			this->w = size.x;
			this->h = size.y;
		}

		glm::vec2 Position()
		{
			return { x, y };
		}

		glm::vec2 Size()
		{
			return { w, h };
		}
	};
}