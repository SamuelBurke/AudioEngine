#ifndef SNAKE_H
#define SNAKE_H

#include "Player.h"
#include "foundations/Component.h"

#include <memory>

class Foundation::VertexArray;
class Foundation::Texture;
class Foundation::Transform;

class Snake : public Foundation::Component
{
public:
	void OnInit() override;
	void OnUpdate(float _deltaTime) override;

	std::shared_ptr<Foundation::VertexArray> GetModel();
	std::shared_ptr<Foundation::Texture> GetTexture();

	glm::vec3 GetPlayerPosition();

private:
	Player m_player;

	std::shared_ptr<Foundation::VertexArray> m_defaultCube;
	std::shared_ptr<Foundation::Texture> m_defaultTexture;
	std::shared_ptr<Foundation::Transform> m_transform;

};

#endif // !SNAKE_H
