#include "renderer.h"
namespace Engine
{
	Renderer::Renderer()
	{
		vertexCount = 0; 
		indexCount = 0;
		VAO = 0;
		VBO = 0;
		EBO = 0;
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::init()
	{
		unsigned int offset = 0;
		for (unsigned int i = 0; i < RENDERER_MAX_INDEX_COUNT; i += 6)
		{
			indices[i + 0] = 0 + offset;
			indices[i + 1] = 1 + offset;
			indices[i + 2] = 2 + offset;
			indices[i + 3] = 2 + offset;
			indices[i + 4] = 3 + offset;
			indices[i + 5] = 0 + offset;

			offset += 4;
		}

		batchShader = Shader("Shaders/Batch.vert", "Shaders/Batch.frag");

		//Generate buffers

		glGenVertexArrays(1, &VAO);

		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		//Allocate buffers
		glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, RENDERER_MAX_VERTEX_COUNT * sizeof(Vertex), nullptr, GL_DYNAMIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), &indices[0], GL_STATIC_DRAW);

		//Position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Position));
		glEnableVertexAttribArray(0);

		//Color attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Color));
		glEnableVertexAttribArray(1);

		//Unbind stuff
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	void Renderer::beginFrame()
	{
		vertexCount = 0;
		indexCount = 0;

		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		batchShader.use();
	}

	void Renderer::endFrame()
	{
		glBufferSubData(GL_ARRAY_BUFFER, 0, vertices.size() * sizeof(Vertex), vertices.data());


		//Bind vao
		glBindVertexArray(VAO);
		// Draw primitives, number of indices, datatype of indices, index of indices
		glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
	}

	void Renderer::drawQuad(float x, float y, float w, float h, float r, float g, float b, float a)
	{
		//Bottom right
		Vertex v0;
		v0.Position = { x + w, y - h, 1.f };
		v0.Color = { r,g,b,a };
		vertices[vertexCount] = v0;
		vertexCount++;

		//Top right
		Vertex v1;
		v1.Position = { x + w, y, 1.f };
		v1.Color = { r, g, b, a };
		vertices[vertexCount] = v1;
		vertexCount++;

		//Top left
		Vertex v2;
		v2.Position = { x, y, 1.f };
		v2.Color = { r, g, b, a };
		vertices[vertexCount] = v2;
		vertexCount++;

		//Bottom left
		Vertex v3;
		v3.Position = { x, y - h, 1.f };
		v3.Color = { r, g, b, a };
		vertices[vertexCount] = v3;
		vertexCount++;

		indexCount += 6;
	}
}