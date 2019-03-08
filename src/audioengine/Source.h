#ifndef AUDIOENGINE_SOURCE_H
#define AUDIOENGINE_SOURCE_H

#include <memory>
#include <string>

namespace AudioEngine
{

struct SoundImpl;

class Source
{
public:
	Source();
	Source(std::string _filePath);
	void Load(std::string _filePath);
	void Play();

private:
	std::shared_ptr<SoundImpl> m_impl;
};

}

#endif