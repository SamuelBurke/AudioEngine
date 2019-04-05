#ifndef FOUNDATION_ENTITY_H
#define FOUNDATION_ENTITY_H

#include "Component.h"

#include <memory>
#include <vector>

#define ADDCOMPONENT \
	std::shared_ptr<T> rtn = std::make_shared<T>(); \
	rtn->m_entity = m_self; \
	rtn->m_began = false;   \
	m_components.push_back(rtn);

namespace Foundation
{
class Foundations;

class Entity
{
	friend class Foundations;

public:
	template <typename T>
	std::shared_ptr<T> GetComponent()
	{
		for (size_t i = 0; i < m_components.size(); i++)
		{
			std::shared_ptr<T> currentComponent = std::dynamic_pointer_cast<T>(m_components.at(i));

			if (currentComponent)
			{
				return currentComponent;
			}
		}

		return nullptr;
		throw std::exception();
	}

	template <typename T>
	std::shared_ptr<T> AddComponent()
	{
		ADDCOMPONENT
		rtn->OnInit();

		return rtn;
	}

	std::shared_ptr<Foundations> GetFoundation();

private:
	void Update(float _deltaTime);
	void Display();

	std::vector<std::shared_ptr<Component>> m_components;
	std::weak_ptr<Entity> m_self;
	std::weak_ptr<Foundations> m_foundation;


};
}

#endif // !FOUNDATION_ENTITY_H
