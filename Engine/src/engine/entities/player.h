#pragma once
#include <entities/ientity.h>
namespace Engine
{
	class Player : public IEntity
	{
	public:
		Player(glm::vec2 position, glm::vec2 size, Color c);
		~Player();
		void input();

		void update(long double dt);

		void render();
	private:
		glm::vec2 position, size;
		Color color;
	};
}