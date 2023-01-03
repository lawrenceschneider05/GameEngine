#include "InputManager.h"
#include <iostream>
namespace Engine
{
	InputManager::InputManager()
	{

	}

	InputManager::~InputManager()
	{

	}

	bool InputManager::keyDown(i32 key)
	{
		return keysDown[key];
	}

	void InputManager::keyPressed(i32 glfwKey)
	{
		keysDown[keyMap[glfwKey]] = true;
	}

	void InputManager::keyReleased(i32 glfwKey)
	{
		keysDown[keyMap[glfwKey]] = false;
	}
}