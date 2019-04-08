#include "Snake.h"

#include <iostream>

void Snake::OnInit()
{
	m_transform = GetTransform();

	m_defaultCube = std::make_shared<Foundation::VertexArray>("../resources/models/cube.obj");
	m_defaultTexture = std::make_shared<Foundation::Texture>("../resources/textures/default.png");

	m_player.Init(m_transform);
}

void Snake::OnUpdate(float _deltaTime)
{
	m_player.Update(_deltaTime);
}

std::shared_ptr<Foundation::VertexArray> Snake::GetModel()
{
	return m_defaultCube;
}

std::shared_ptr<Foundation::Texture> Snake::GetTexture()
{
	return m_defaultTexture;
}

glm::vec3 Snake::GetPlayerPosition()
{
	return m_player.GetPlayerPosition();
}