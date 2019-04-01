#ifndef AUDIOENGINE_ENVIRONMENT_H
#define AUDIOENGINE_ENVIRONMENT_H

namespace AudioEngine
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

#endif // !AUDIOENGINE_ENVIRONMENT_H
