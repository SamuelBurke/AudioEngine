#ifndef PLAYER_H
#define PLAYER_H

#include "foundations/Input.h"

#include <memory>

class Player
{
public:
	void Update(float _deltaTime);

private:
	AudioEngine::Input m_input;
};

#endif // !SNAKE_H