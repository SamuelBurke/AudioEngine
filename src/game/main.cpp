#include <audioengine/audioengine.h>
#include <foundations/fundamentals.h>

#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<AudioEngine::Foundations> foundation = AudioEngine::Foundations::Init();
	std::shared_ptr<AudioEngine::Entity> temp = foundation->AddEntity();
	std::shared_ptr<AudioEngine::Component> temp2 = temp->AddComponent<AudioEngine::Component>();

	std::shared_ptr<AudioEngine::AudioMaster> am = AudioEngine::AudioMaster::initialise();
	std::shared_ptr<AudioEngine::Source> sound = std::make_shared<AudioEngine::Source>("../resources/audio/dixie_horn.ogg");
	sound->Play();

	foundation->Loop();

	return 0;
}