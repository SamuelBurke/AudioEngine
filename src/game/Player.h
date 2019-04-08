#ifndef PLAYER_H
#define PLAYER_H

#include "foundations/VertexArray.h"
#include "foundations/Shader.h"
#include "foundations/Texture.h"
#include "foundations/Input.h"
#include "foundations/Transform.h"
#include "foundations/Component.h"

#include <memory>

class Player
{
public:
	void Init(std::shared_ptr<Foundation::Transform> _transform);
	void Update(float _deltaTime);

	glm::vec3 GetPlayerPosition();

private:
	float m_speed;
	glm::vec3 m_direction;
	glm::vec3 m_playerPos;

	std::shared_ptr<Foundation::Transform> m_transform;

	Foundation::Input m_input;
};

#endif // !PLAYER_H
