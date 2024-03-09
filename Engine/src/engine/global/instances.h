#pragma once
#include <glad/glad.h>
#include <ecs/ecs.h>
#include <window/window.h>
#include <input/InputManager.h>
#include <renderer/renderer.h>
#include <camera/camera.h>


namespace Engine
{
	namespace Global
	{
		inline Window* window;
		inline InputManager* input_manager;
		inline Renderer* renderer;
		inline Camera* camera;
		inline ECS* ecs;
	}
}