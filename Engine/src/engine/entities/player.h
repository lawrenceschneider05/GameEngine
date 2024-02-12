#pragma once
#include <entities/ientity.h>
namespace Engine
{
	class Player : public IEntity
	{
	public:
		Player(glm::vec2 position, glm::vec2 size, Color c, EntityType type);
		~Player();
		void input();

		void update(long double dt);

		void render();

		void collisionWith(IEntity* e);
	private:
		Color color;
	};
}