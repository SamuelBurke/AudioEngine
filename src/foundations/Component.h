#ifndef AUDIOENGINE_COMPONENT_H
#define AUDIOENGINE_COMPONENT_H

#include <memory>

namespace AudioEngine
{
class Entity;
class Foundations;

class Component
{
	friend class Entity;

public:
	virtual ~Component();

	std::shared_ptr<Foundations> GetFoundation();
	std::shared_ptr<Entity> GetEntity();

private:
	std::weak_ptr<Entity> m_entity; // parent entity
	bool m_began;

	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnUpdate(float _deltaTime);
	virtual void OnDisplay();
};
}

#endif // !AUDIOENGINE_COMPONENT_H
