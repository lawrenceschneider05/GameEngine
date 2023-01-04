#pragma once
#include <glad/glad.h>
#include <src/window/window.h>
#include <src/input/InputManager.h>
#include <src/renderer/renderer.h>

namespace Engine
{
	namespace Global
	{
		Window* window;
		InputManager* input;
		Renderer* renderer;
	}
}