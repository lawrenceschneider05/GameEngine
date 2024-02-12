#pragma once
#include <renderer/Shader.h>
#include <array>
#include <renderer/colors.h>
#include "glm/glm.hpp"

#define RENDERER_MAX_QUAD_COUNT 1024 * 1000
#define RENDERER_MAX_VERTEX_COUNT RENDERER_MAX_QUAD_COUNT * 4
#define RENDERER_MAX_INDEX_COUNT RENDERER_MAX_QUAD_COUNT * 6


namespace Engine
{

	struct Vec3
	{
		float array[3];
	};
	struct Vec4
	{
		float array[4];
	};
	struct Vertex
	{
		Vec3 Position;
		Vec4 Color;
	};

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void init();
		void beginFrame();
		void endFrame();
		void drawQuad(float x, float y, float w, float h, float r, float g, float b, float a);
		void drawQuad(float x, float y, float w, float h, Color c);
		void drawQuad(glm::vec2 position, glm::vec2 size, Color c);
		Shader& getBatchShader()
		{
			return batchShader;
		}

		int quadCount()
		{
			return indexCount / 6;
		}
	private:
		std::array<Vertex, RENDERER_MAX_VERTEX_COUNT> vertices;
		std::array<unsigned int, RENDERER_MAX_INDEX_COUNT> indices;
		unsigned int vertexCount = 0;
		unsigned int indexCount = 0;
		Shader batchShader;
		unsigned int VAO, VBO, EBO;
	};
}