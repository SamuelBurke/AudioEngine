#include <audioengine/audioengine.h>

#include <iostream>

int main()
{
	std::shared_ptr<AudioEngine::AudioMaster> am = AudioEngine::AudioMaster::initialise();

	std::shared_ptr<AudioEngine::Source> sound = std::make_shared<AudioEngine::Source>("../resources/audio/dixie_horn.ogg");
	sound->Play();

	getchar();

	return 0;
}