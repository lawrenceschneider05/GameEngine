#pragma once
#include <vendor/include/glm/fwd.hpp>
namespace Engine
{
	namespace Global
	{
		void initGLFW();
		void initGLAD();
		void setUpGL();
		glm::vec2 getMousePos();
		bool keyDown(int key);
	}
}