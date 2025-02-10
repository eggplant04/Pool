#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"
#include "CueBall.h"
#include "Hole.h"

class PhysicsApp : public aie::Application {
public:
	PhysicsApp();
	virtual ~PhysicsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void Pocket(PhysicsObject* other);

	glm::vec2 ScreenToWorld(glm::vec2 screenPos);

protected:
	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;
	aie::Texture* m_poolTable;
	PhysicsScene* m_physicsScene;

	CueBall* m_cueBall;
	glm::vec2 m_cueForce = glm::vec2(0);

	const float m_extents = 100;
	const float m_aspectRatio = 16.0f / 9.0f;

};