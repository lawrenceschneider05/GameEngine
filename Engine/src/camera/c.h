#pragma once
#include <glm/glm.hpp>
#include <glm/ext/matrix_transform.hpp>

class C
{
public:
	C() : position(0.0f,0.0f), cameraMatrix(1.0f), scale(1.0f)
	{
		
	}

	~C()
	{

	}

	void update()
	{
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