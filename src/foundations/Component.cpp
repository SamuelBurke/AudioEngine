#include "Component.h"
#include "Entity.h"
#include "Transform.h"

#include <iostream>

using namespace Foundation;

Component::~Component()
{
}

void Component::OnInit()
{
}

void Component::OnBegin()
{
}

void Component::OnUpdate(float _deltaTime)
{
	//std::cout << "working" << std::endl;
}

void Component::OnDisplay()
{
}

std::shared_ptr<Entity> Component::GetEntity()
{
	return m_entity.lock();
}

std::shared_ptr<Foundations> Component::GetFoundation()
{
	return GetEntity()->GetFoundation();
}

std::shared_ptr<Transform> Component::GetTransform()
{
	return GetEntity()->GetComponent<Transform>();
}