#include "AudioMaster.h"

using namespace AudioEngine;

std::shared_ptr<AudioMaster> AudioMaster::initialise()
{
	std::shared_ptr<AudioMaster> rtn = std::make_shared<AudioMaster>();

	rtn->m_device = alcOpenDevice(NULL);

	if (!rtn->m_device)
	{
		throw std::exception();
	}

	rtn->m_context = alcCreateContext (rtn->m_device, NULL);

	if (!rtn->m_context)
	{
		alcCloseDevice(rtn->m_device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(rtn->m_context))
	{
		alcDestroyContext(rtn->m_context);
		alcCloseDevice(rtn->m_device);
		throw std::exception();
	}

	return rtn;
}

void AudioMaster::cleanup()
{
	alcMakeContextCurrent(NULL);
	alcDestroyContext(m_context);
	alcCloseDevice(m_device);
}