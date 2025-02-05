#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "PhysicsScene.h"

class PhysicsApp : public aie::Application {
public:

	PhysicsApp();
	virtual ~PhysicsApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	glm::vec2 ScreenToWorld(glm::vec2 screenPos);

protected:
	aie::Renderer2D* m_2dRenderer;
	aie::Font* m_font;
	aie::Texture* m_poolTable;
	PhysicsScene* m_physicsScene;

	float m_cameraX;
	float m_cameraY;
};