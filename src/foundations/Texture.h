#ifndef FOUNDATION_TEXTURE_H
#define FOUNDATION_TEXTURE_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>

namespace Foundation
{
class Texture
{
public:
	Texture(std::string _filePath);

	glm::vec2 GetSize();
	GLuint GetID();

private:
	GLuint m_id;
	glm::vec2 m_size;

};
}

#endif // !FOUNDATION_TEXTURE_H
