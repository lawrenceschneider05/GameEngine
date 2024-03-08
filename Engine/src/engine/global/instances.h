#pragma once
#include <glad/glad.h>
#include <window/window.h>
#include <input/InputManager.h>
#include <renderer/renderer.h>
#include <camera/camera.h>
#include <components/component_manager.h>
#include <entities/entity_manager.h>

namespace Engine
{
	namespace Global
	{
		inline Window* window;
		inline InputManager* input_manager;
		inline Renderer* renderer;
		inline Camera* camera;
		inline EntityManager* entity_manager;
		inline ComponentManager* component_manager;
	}
}