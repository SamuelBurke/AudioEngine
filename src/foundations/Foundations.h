#ifndef AUDIOENGINE_FOUNDATIONS_H
#define AUDIOENGINE_FOUNDATIONS_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "Window.h"
#include "Environment.h"

namespace AudioEngine
{

class Foundations
{
public:
	static std::shared_ptr<Foundations> Init();

	void Loop();
	void CleanUp();

	std::shared_ptr<Entity> AddEntity();

	template <typename T>
	std::shared_ptr<T> GetComponent();

private:
	bool m_quit;

	std::vector<std::shared_ptr<Entity>> m_entities;
	std::weak_ptr<Foundations> m_self;

	Window m_window;
	Environment m_environment;
};

template <typename T>
inline std::shared_ptr<T> Foundations::GetComponent()
{
	for (std::shared_ptr<Entity> e : m_entities)
	{
		if (e->GetComponent<T>())
		{
			return e->GetComponent<T>();
		}
	}

	throw std::exception();
}

}

#endif // !AUDIOENGINE_FOUNDATIONS_H