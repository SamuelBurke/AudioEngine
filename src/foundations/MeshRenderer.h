#ifndef FOUNDATIONS_MESHRENDERER_H
#define FOUNDATIONS_MESHRENDERER_H

#include "Component.h"

#include <memory>

namespace Foundation
{
class VertexArray;
class Shader;
class Texture;

class MeshRenderer : public Component
{
public:
	void OnInit();

	void SetMesh(std::weak_ptr<VertexArray> _mesh);
	std::shared_ptr<VertexArray> GetMesh();

	void SetMaterial(std::weak_ptr<Texture> _texture);
	std::shared_ptr<Texture> GetMaterial();

private:
	void OnUpdate(float _deltaTime) override;
	void OnDisplay() override;

	float m_angle;

	std::shared_ptr<Shader> m_shader;
	std::weak_ptr<VertexArray> m_currentMesh;
	std::weak_ptr<Texture> m_currentTexture;
};
}

#endif // !FOUNDATIONS_MESHRENDERER_H
