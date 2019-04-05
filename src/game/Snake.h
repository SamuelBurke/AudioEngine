#ifndef SNAKE_H
#define SNAKE_H

#include "foundations/Component.h"
#include "Player.h"

#include <memory>

class Snake : public Foundation::Component
{
public:
	void OnInit() override;
	void OnUpdate(float _deltaTime) override;

private:
	Player m_player;

};

#endif // !SNAKE_H
