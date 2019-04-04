#include "game/Player.h"

#include <iostream>

void Player::Update(float _deltaTime)
{
	m_input.Update();

	if (m_input.isKeyPressed(SDL_SCANCODE_W) || m_input.isKeyPressed(SDL_SCANCODE_UP)) { std::cout << "w working" << std::endl; }

	if (m_input.isKeyPressed(SDL_SCANCODE_S) || m_input.isKeyPressed(SDL_SCANCODE_DOWN)) { std::cout << "s working" << std::endl; }

	if (m_input.isKeyPressed(SDL_SCANCODE_D) || m_input.isKeyPressed(SDL_SCANCODE_RIGHT)) { std::cout << "d working" << std::endl; }

	if (m_input.isKeyPressed(SDL_SCANCODE_A) || m_input.isKeyPressed(SDL_SCANCODE_LEFT)) { std::cout << "a working" << std::endl; }
}