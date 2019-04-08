#include <audioengine/audioengine.h>
#include <foundations/fundamentals.h>
#include "Snake.h"

#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<Foundation::Foundations> foundation = Foundation::Foundations::Init();
	std::shared_ptr<Foundation::Entity> user = foundation->AddEntity();
	std::shared_ptr<Foundation::Entity> camera = foundation->AddEntity();

	std::shared_ptr<Foundation::Camera> cam = camera->AddComponent<Foundation::Camera>();
	std::shared_ptr<Foundation::Transform> trans = camera->AddComponent<Foundation::Transform>();

	std::shared_ptr<Foundation::Transform> transform = user->AddComponent<Foundation::Transform>();
	std::shared_ptr<Snake> snake = user->AddComponent<Snake>();
	std::shared_ptr<Foundation::MeshRenderer> meshRenderer = user->AddComponent<Foundation::MeshRenderer>();

	//std::shared_ptr<AudioEngine::AudioMaster> am = AudioEngine::AudioMaster::initialise();
	std::shared_ptr<AudioEngine::Source> sound = std::make_shared<AudioEngine::Source>("../resources/audio/dixie_horn.ogg");
	sound->Play();

	foundation->Loop();

	//am->cleanup();

	return 0;
}