#include "Snake.h"

#include <iostream>

void Snake::OnInit()
{
	std::cout << "snake init" << std::endl;
}

void Snake::OnUpdate(float _deltaTime)
{
	m_player.Update(_deltaTime);
}
