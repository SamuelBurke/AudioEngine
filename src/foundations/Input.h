#ifndef AUDIOENGINE_INPUT_H
#define AUDIOENGINE_INPUT_H

#include <SDL2/SDL.h>

namespace AudioEngine
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

#endif // !AUDIOENGINE_INPUT_H
