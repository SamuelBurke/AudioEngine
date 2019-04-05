#include <audioengine/audioengine.h>
#include <foundations/fundamentals.h>
#include "Snake.h"

#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<Foundation::Foundations> foundation = Foundation::Foundations::Init();
	std::shared_ptr<Foundation::Entity> temp = foundation->AddEntity();
	std::shared_ptr<Snake> temp2 = temp->AddComponent<Snake>();

	std::shared_ptr<AudioEngine::AudioMaster> am = AudioEngine::AudioMaster::initialise();
	std::shared_ptr<AudioEngine::Source> sound = std::make_shared<AudioEngine::Source>("../resources/audio/dixie_horn.ogg");
	sound->Play();

	foundation->Loop();

	am->cleanup();

	return 0;
}