#ifndef FOUNDATION_VERTEXBUFFER_H
#define FOUNDATION_VERTEXBUFFER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace Foundation
{
class VertexBuffer
{
public:
	VertexBuffer();
	void Add(glm::vec2 _value);
	void Add(glm::vec3 _value);
	void Add(glm::vec4 _value);

	int GetComponents();
	int GetDataSize();
	GLuint GetID();

private:
	GLuint m_id;
	int m_components;
	std::vector<GLfloat> m_data;
	bool m_dirty;
};
}

#endif // !FOUNDATION_VERTEXBUFFER_H
