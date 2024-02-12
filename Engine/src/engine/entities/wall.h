#pragma once
#include "ientity.h"

namespace Engine
{
	class Wall : public IEntity
	{
	public:
		Wall(glm::vec2 position, glm::vec2 size, Color c, EntityType type);
		~Wall();
		void input();
		void update(long double dt);
		void render();

		void collisionWith(IEntity* e);
	private:
		Color color;
	};
}