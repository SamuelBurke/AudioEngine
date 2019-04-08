#ifndef FOUNDATION_COMPONENT_H
#define FOUNDATION_COMPONENT_H

#include <memory>

namespace Foundation
{
class Entity;
class Foundations;
class Transform;

class Component
{
	friend class Entity;

public:
	virtual ~Component();

	std::shared_ptr<Foundations> GetFoundation();
	std::shared_ptr<Entity> GetEntity();
	std::shared_ptr<Transform> GetTransform();

private:
	std::weak_ptr<Entity> m_entity; // parent entity
	bool m_began;

	virtual void OnInit();
	virtual void OnBegin();
	virtual void OnUpdate(float _deltaTime);
	virtual void OnDisplay();
};
}

#endif // !FOUNDATION_COMPONENT_H
