#include "Environment.h"

#include <SDL2/SDL.h>

using namespace AudioEngine;

void Environment::Init()
{
	m_deltaTime = 0;
	m_lastTime = SDL_GetTicks();
}

float Environment::CalculateDeltaTime()
{
	float time = SDL_GetTicks();
	float difference = time - m_lastTime;
	m_deltaTime = difference / 1000.0f;
	m_lastTime = time;

	return m_deltaTime;
}