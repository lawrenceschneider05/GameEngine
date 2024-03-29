#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "input/InputManager.h"
namespace Engine
{
	class Camera
	{
	public:
		bool cameraMove = true;
		Camera() : position(-250.0f, -250.0f), cameraMatrix(1.0f), scale(1.0f)
		{

		}

		~Camera()
		{

		}

		glm::vec2 convertScreenToWorldCoordinates(glm::vec2 screenCords)
		{
			//screenCords -= glm::vec2(width / 4, height / 4);
			screenCords += position;
			screenCords /= scale;
			
			return screenCords;
		}

		void update(InputManager& input, long double dt)
		{
			if (cameraMove)
			{
				if (input.keyDown(KEY_W))
				{
					position.y += 300 * dt;
				}
				else if (input.keyDown(KEY_S))
				{
					position.y -= 300 * dt;
				}
				if (input.keyDown(KEY_A))
				{
					position.x -= 300 * dt;
				}
				else if (input.keyDown(KEY_D))
				{
					position.x += 300 * dt;
				}
				if (input.keyDown(KEY_SPACE))
				{
					scale -= 2.5f * dt;
					if (scale < 0)
					{
						scale = 0;
					}
					
				}
				else if (input.keyDown(KEY_LEFT_SHIFT))
				{
					scale += 2.5f * dt;

				}
			}
			glm::vec3 translate(-position.x, -position.y, 0.0f);
			cameraMatrix = glm::translate(orthoMatrix, translate);

			glm::vec3 sc(scale, scale, 0.0f);
			cameraMatrix = glm::scale(cameraMatrix, sc);
		}

		void init(int w, int h)
		{
			width = w;
			height = h;

			orthoMatrix = glm::ortho(0.0f, (float)width, 0.0f, (float)height);
		}

		void setPosition(const glm::vec2& newPosition)
		{
			position = newPosition;
		}

		glm::vec2 getPosition()
		{
			return position;
		}

		void setScale(float newScale)
		{
			scale = newScale;
		}

		float getScale()
		{
			return scale;
		}

		glm::mat4 getOrthoMatrix()
		{
			return cameraMatrix;
		}
	private:
		int width, height;
		float scale;
		glm::vec2 position;
		glm::mat4 cameraMatrix;
		glm::mat4 orthoMatrix;
	};
}