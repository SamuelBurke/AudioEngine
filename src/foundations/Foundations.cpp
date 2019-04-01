#include "Foundations.h"

using namespace AudioEngine;

std::shared_ptr<Foundations> AudioEngine::Foundations::Init()
{
	std::shared_ptr<Foundations> rtn = std::make_shared<Foundations>();

	rtn->m_quit = true;

	rtn->m_window.InitWin();

	return rtn;
}

void Foundations::Loop()
{
	m_quit = false;

	while (!m_quit)
	{
		SDL_Event e = { 0 };

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				CleanUp();
			}
		}

		float deltaTime = m_environment.CalculateDeltaTime();

		for (std::vector<std::shared_ptr<Entity> >::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Update(deltaTime);
		}

		m_window.ClearBuff();

		for (std::vector<std::shared_ptr<Entity> >::iterator it = m_entities.begin(); it != m_entities.end(); it++)
		{
			(*it)->Display();
		}

		m_window.SwapWin();

	}
}

void Foundations::CleanUp()
{
	m_quit = true;
}

std::shared_ptr<Entity> Foundations::AddEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	m_entities.push_back(rtn);
	rtn->m_self = rtn;
	rtn->m_foundation = m_self;

	return rtn;
}