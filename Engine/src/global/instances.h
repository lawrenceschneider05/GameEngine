#pragma once
#include <glad/glad.h>
#include <src/window/window.h>
#include <src/input/InputManager.h>
#include <src/renderer/renderer.h>
#include <src/camera/camera.h>

namespace Engine
{
	namespace Global
	{
		inline Window* window;
		inline InputManager* input;
		inline Renderer* renderer;
		inline Camera* camera;
	}
}