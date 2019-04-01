#include "Entity.h"

using namespace AudioEngine;

void Entity::Update(float _deltaTime)
{
	for (std::vector<std::shared_ptr<Component> >::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		if (!(*it)->m_began)
		{
			(*it)->OnBegin();
			(*it)->m_began = true;
		}

		(*it)->OnUpdate(_deltaTime);
	}
}

void Entity::Display()
{
	for (std::vector<std::shared_ptr<Component> >::iterator it = m_components.begin(); it != m_components.end(); it++)
	{
		(*it)->OnDisplay();
	}
}

std::shared_ptr<Foundations> Entity::GetFoundation()
{
	return m_foundation.lock();
}