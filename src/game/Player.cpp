#include "Player.h"
#include "foundations/Foundations.h"
#include "foundations/Camera.h"

#include <iostream>
#include <glm/ext.hpp>

void Player::Init(std::shared_ptr<Foundation::Transform> _transform)
{
	m_transform = _transform;

	m_speed = 5.0f;
	m_direction = glm::vec3(0.0f, 1.0f, 0.0f);

	m_playerPos = glm::vec3(0.0f, 0.0f, -18.0f);
	m_transform->SetPosition(m_playerPos);
}

void Player::Update(float _deltaTime)
{
	m_input.Update();

	if (m_input.isKeyPressed(SDL_SCANCODE_W) || m_input.isKeyPressed(SDL_SCANCODE_UP)) { std::cout << "w working" << std::endl; }

	if (m_input.isKeyPressed(SDL_SCANCODE_S) || m_input.isKeyPressed(SDL_SCANCODE_DOWN)) { std::cout << "s working" << std::endl; }

	if (m_input.isKeyPressed(SDL_SCANCODE_D) || m_input.isKeyPressed(SDL_SCANCODE_RIGHT)) { std::cout << "d working" << std::endl; }

	if (m_input.isKeyPressed(SDL_SCANCODE_A) || m_input.isKeyPressed(SDL_SCANCODE_LEFT)) { std::cout << "a working" << std::endl; }

	m_playerPos = glm::vec3(m_direction * m_speed * _deltaTime);
	m_transform->Translate(m_playerPos);
}

glm::vec3 Player::GetPlayerPosition()
{
	return m_transform->GetPosition();
}