#ifndef FOUNDATION_ENVIRONMENT_H
#define FOUNDATION_ENVIRONMENT_H

namespace Foundation
{
class Environment
{
public:
	void Init();
	float CalculateDeltaTime();

private:
	float m_deltaTime;
	float m_lastTime;
};
}

#endif // !FOUNDATION_ENVIRONMENT_H
