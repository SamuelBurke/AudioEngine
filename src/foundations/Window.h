#ifndef FOUNDATION_WINDOW_H
#define FOUNDATION_WINDOW_H

#include <SDL2/SDL.h>

namespace Foundation
{
class Window
{
public:
	void InitWin();
	void ClearBuff();
	void SwapWin();

	SDL_Window* GetWindow();

	static int GetWidth();
	static int GetHeight();

private:
	bool InitGL();

	static int m_width;
	static int m_height;

	SDL_Window* m_window;
};
}

#endif // !FOUNDATION_WINDOW_H