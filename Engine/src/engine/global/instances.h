#pragma once
#include <glad/glad.h>
#include <window/window.h>
#include <input/InputManager.h>
#include <renderer/renderer.h>
#include <camera/camera.h>
#include <entities/entitymanager.h>

namespace Engine
{
	namespace Global
	{
		inline Window* window;
		inline InputManager* inputManager;
		inline Renderer* renderer;
		inline Camera* camera;
		inline EntityManager* entityManager;
	}
}