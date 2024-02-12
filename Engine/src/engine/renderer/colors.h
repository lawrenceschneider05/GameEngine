#pragma once
namespace Engine
{
	struct Color
	{
		float r, g, b, a = 1.0f;
	};

	namespace Colors
	{
		const Color RED{ 1.0f,0,0};
		const Color GREEN{ 0,1.0f,0 };
		const Color BLUE{ 0,0,1.0f };
		const Color BLACK{ 0.0f,0.0f,0.0f };
	}
}