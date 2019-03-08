#ifndef AUDIOENGINE_AUDIOMASTER_H
#define AUDIOENGINE_AUDIOMASTER_H

#include <AL/al.h>
#include <AL/alc.h>

#include <memory>

namespace AudioEngine
{

class AudioMaster
{
public:
	static std::shared_ptr<AudioMaster> initialise();
	void cleanup();

private:
	ALCdevice* m_device;
	ALCcontext* m_context;
};

}

#endif