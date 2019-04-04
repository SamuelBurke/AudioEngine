#ifndef AUDIOENGINE_CAMERA_H
#define AUDIOENGINE_CAMERA_H

#define GLM_FORCE_CTOR_INT

#include "Component.h"
#include "Transform.h"
#include "Window.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace AudioEngine
{
class Camera : public Component
{
public:
	void OnInit() override;
	void OnUpdate(float _deltaTime) override;

	glm::mat4 GetProjection();
	glm::mat4 GetView();

private:
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;

	float m_radius;
	float m_near;
	float m_far;

	float m_cameraSpeed;

	glm::vec3 m_cameraFront;
	glm::vec3 m_cameraRight;
	glm::vec3 m_cameraUp;

	Transform m_transform;
	Window m_window;
};
}

#endif // !AUDIOENGINE_CAMERA_H
