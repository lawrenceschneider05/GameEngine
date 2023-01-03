#pragma once
#include <src/types/types.h>
#include <unordered_map>
#include "GLFW/glfw3.h"

#define KEY_A 1
#define KEY_B 2
#define KEY_C 3
#define KEY_D 4
#define KEY_E 5
#define KEY_F 6
#define KEY_G 7
#define KEY_H 8
#define KEY_I 9
#define KEY_J 10
#define KEY_K 11
#define KEY_L 12
#define KEY_M 13
#define KEY_N 14
#define KEY_O 15
#define KEY_P 16
#define KEY_Q 17
#define KEY_R 18
#define KEY_S 19
#define KEY_T 20
#define KEY_U 21
#define KEY_V 22
#define KEY_W 23
#define KEY_X 24
#define KEY_Y 25
#define KEY_Z 26

namespace Engine
{
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void keyPressed(i32 glfwKey);
		void keyReleased(i32 glfwKey);
		bool keyDown(i32 key);

	private:

		bool keysDown[26] = {};
		// A = 0
		// B = 1
		// C = 2
		// ...
		std::unordered_map<int, int> keyMap = { {GLFW_KEY_A, KEY_A},
												{GLFW_KEY_B, KEY_B},
												{GLFW_KEY_C, KEY_C},
												{GLFW_KEY_D, KEY_D},
												{GLFW_KEY_E, KEY_E},
												{GLFW_KEY_F, KEY_F},
												{GLFW_KEY_G, KEY_G},
												{GLFW_KEY_H, KEY_H},
												{GLFW_KEY_I, KEY_I},
												{GLFW_KEY_J, KEY_J},
												{GLFW_KEY_K, KEY_K},
												{GLFW_KEY_L, KEY_L},
												{GLFW_KEY_M, KEY_M},
												{GLFW_KEY_N, KEY_N},
												{GLFW_KEY_O, KEY_O},
												{GLFW_KEY_P, KEY_P},
												{GLFW_KEY_Q, KEY_Q},
												{GLFW_KEY_R, KEY_R},
												{GLFW_KEY_S, KEY_S},
												{GLFW_KEY_T, KEY_T},
												{GLFW_KEY_U, KEY_U},
												{GLFW_KEY_V, KEY_V},
												{GLFW_KEY_W, KEY_W},
												{GLFW_KEY_X, KEY_X},
												{GLFW_KEY_Y, KEY_Y},
												{GLFW_KEY_Z, KEY_Z},
		};
	};
}