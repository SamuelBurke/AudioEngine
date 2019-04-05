#ifndef FOUNDATION_INPUT_H
#define FOUNDATION_INPUT_H

#include <SDL2/SDL.h>

namespace Foundation
{
class Input
{
public:
	//void Init();
	void Update();

	bool isKeyPressed(SDL_Scancode _keyCode); // returns true when key is pressed

private:
	const Uint8* m_currentKey;
};
}

#endif // !FOUNDATION_INPUT_H
