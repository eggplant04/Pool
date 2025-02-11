#include "PhysicsApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Gizmos.h"
#include "glm/vec2.hpp"
#include "glm/vec4.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "string"
#include "Circle.h"
#include "Plane.h"
#include "Box.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include "Spring.h"
#include "SoftBody.h"

using namespace std;

const float m_extents = 100;
const float m_aspectRatio = 16.0f / 9.0f;

PhysicsApp::PhysicsApp() {

}

PhysicsApp::~PhysicsApp() {

}

bool PhysicsApp::startup() 
{


	m_2dRenderer = new aie::Renderer2D();
	// increase the 2d line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	//m_poolTable = new aie::Texture("./textures/table2.png");

	// PhysicsScene
	m_physicsScene = new PhysicsScene();
	m_physicsScene->SetGravity(glm::vec2(0));
	m_physicsScene->SetTimeStep(0.001);
	
	// POOL TABLE
	
	// Cue ball
	m_cueBall = new CueBall(glm::vec2(-50, 0), glm::vec2(0, 0), 18.0f, 4, glm::vec4(1));
	m_physicsScene->AddActor(m_cueBall);
	
	// Billard balls
	Circle* ball1 = new Circle(glm::vec2(50, 0), glm::vec2(0), 17.0f, 4, glm::vec4(0, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(43, 4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));
	Circle* ball3 = new Circle(glm::vec2(43, -4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball4 = new Circle(glm::vec2(36, 0), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));
	Circle* ball5 = new Circle(glm::vec2(57, 4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball6 = new Circle(glm::vec2(57, -4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));
	Circle* ball7 = new Circle(glm::vec2(50, -8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));
	Circle* ball8 = new Circle(glm::vec2(50, 8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball9 = new Circle(glm::vec2(57, -12), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball10 = new Circle(glm::vec2(57, 12), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));

	Circle* ball11 = new Circle(glm::vec2(64, 0), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball12 = new Circle(glm::vec2(64, 8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));
	Circle* ball13 = new Circle(glm::vec2(64, 16), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball14 = new Circle(glm::vec2(64, -8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball15 = new Circle(glm::vec2(64, -16), glm::vec2(0), 17.0f, 4, glm::vec4(1, 1, 0, 1));
	
	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	m_physicsScene->AddActor(ball3);
	m_physicsScene->AddActor(ball4);
	m_physicsScene->AddActor(ball5);
	m_physicsScene->AddActor(ball6);
	m_physicsScene->AddActor(ball7);
	m_physicsScene->AddActor(ball8);
	m_physicsScene->AddActor(ball9);
	m_physicsScene->AddActor(ball10);
	m_physicsScene->AddActor(ball11);
	m_physicsScene->AddActor(ball12);
	m_physicsScene->AddActor(ball13);
	m_physicsScene->AddActor(ball14);
	m_physicsScene->AddActor(ball15);
	
	// cushions
	Box* cushion1 = new Box(glm::vec2(0, -51), glm::vec2(0, 0), 0.5f, glm::vec2({ 100, 8 }), 0, glm::vec4(0.5, 0, 0, 1));
	cushion1->SetKinematic(true);
	Box* cushion2 = new Box(glm::vec2(0, 51), glm::vec2(0, 0), 0.5f, glm::vec2({ 100, 8 }), 0, glm::vec4(0.5, 0, 0, 1));
	cushion2->SetKinematic(true);														   
	Box* cushion3 = new Box(glm::vec2(-96, 0), glm::vec2(0, 0), 0.5f, glm::vec2({ 8, 45 }), 0, glm::vec4(0.5, 0, 0, 1));
	cushion3->SetKinematic(true);														   
	Box* cushion4 = new Box(glm::vec2(96, 0), glm::vec2(0, 0), 0.5f, glm::vec2({ 8, 45 }), 0, glm::vec4(0.5, 0, 0, 1));
	cushion4->SetKinematic(true);

	m_physicsScene->AddActor(cushion1);
	m_physicsScene->AddActor(cushion2);
	m_physicsScene->AddActor(cushion3);
	m_physicsScene->AddActor(cushion4);

	// Holes
	Hole* hole1 = new Hole(glm::vec2(0, -46), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole2 = new Hole(glm::vec2(88, -44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole3 = new Hole(glm::vec2(-88, -44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole4 = new Hole(glm::vec2(0, 46), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole5 = new Hole(glm::vec2(88, 44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole6 = new Hole(glm::vec2(-88, 44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));

	m_physicsScene->AddActor(hole1);
	m_physicsScene->AddActor(hole2);
	m_physicsScene->AddActor(hole3);
	m_physicsScene->AddActor(hole4);
	m_physicsScene->AddActor(hole5);
	m_physicsScene->AddActor(hole6);

	for (PhysicsObject* object : m_physicsScene->GetActors())
	{
		Hole* hole = dynamic_cast<Hole*>(object);

		if (hole)
		{
			hole->triggerEnter = std::bind(&PhysicsApp::Pocket, this, std::placeholders::_1);
		}
	}
	

	return true;
}

void PhysicsApp::shutdown() 
{
	delete m_font;
	delete m_2dRenderer;
}

void PhysicsApp::update(float deltaTime) 
{
	aie::Gizmos::clear();
	
	m_physicsScene->Update(deltaTime);
	
	UpdatePoolRules();
}

void PhysicsApp::UpdatePoolRules()
{
	// input example
	aie::Input* input = aie::Input::getInstance();

	if (input->isMouseButtonDown(0) && m_physicsScene->GetTotalEnergy() == 0.f && !m_physicsScene->eightBallPotted)
	{
		m_cueBall->SetCanBeHit(true);

		int xScreen, yScreen;
		input->getMouseXY(&xScreen, &yScreen);
		glm::vec2 worldPos = ScreenToWorld(glm::vec2(xScreen, yScreen));

		if (m_physicsScene->needsRespawn)
		{
			aie::Gizmos::add2DCircle(worldPos, 5, 32, glm::vec4(0, 0, 1, 1));
		}
		else
		{
			glm::vec2 cuePos = m_cueBall->GetPosition();
			glm::vec2 direction = worldPos - cuePos;
			float maxDistance = 20.0f;

			float distance = glm::length(direction);
			if (distance > maxDistance)
			{
				direction = glm::normalize(direction) * maxDistance;
				worldPos = cuePos + direction; // Clamp worldPos
				distance = maxDistance;
			}

			glm::vec2 forceDir = -direction; // Direction from clamped position to ball

			if (glm::length(forceDir) > 0)
			{
				forceDir = glm::normalize(forceDir);
			}

			m_cueForce = forceDir * distance * 300.f;

			aie::Gizmos::add2DLine(worldPos, cuePos, glm::vec4(1, 0, 0, 1));
		}
	}

	if (input->isMouseButtonUp(0) && m_cueBall->GetCanBeHit() && !m_physicsScene->eightBallPotted)
	{
		m_cueBall->SetCanBeHit(false);

		if (m_cueBall->GetPosition() == glm::vec2(1000))
		{
			m_physicsScene->needsRespawn = false;
			int xScreen, yScreen;
			input->getMouseXY(&xScreen, &yScreen);
			glm::vec2 worldPos = ScreenToWorld(glm::vec2(xScreen, yScreen));

			m_cueBall->SetPosition(worldPos);
		}
		else
		{
			m_physicsScene->canSwitch = true;

			m_cueBall->ApplyForce(m_cueForce);
		}
	}

	// EndGame
	if (m_physicsScene->eightBallPotted)
	{
		if (m_physicsScene->activePlayer == 1)
		{
			if ((m_physicsScene->p1OnRed && m_physicsScene->redsPotted == 7) || (!m_physicsScene->p1OnRed && m_physicsScene->yellowsPotted == 7))
			{
				m_physicsScene->winnerStr = "Player 1 Wins";
			}
			else
				m_physicsScene->winnerStr = "Player 2 Wins";
		}
		else
		{
			if ((!m_physicsScene->p1OnRed && m_physicsScene->redsPotted == 7) || (m_physicsScene->p1OnRed && m_physicsScene->yellowsPotted == 7))
			{
				m_physicsScene->winnerStr = "Player 2 Wins";
			}
			else
				m_physicsScene->winnerStr = "Player 1 Wins";
		}
	}

	if (m_physicsScene->GetTotalEnergy() == 0.f)
	{
		if (m_physicsScene->canSwitch && (!m_physicsScene->potted || m_physicsScene->needsRespawn))
		{
			if (m_physicsScene->activePlayer == 1)
				m_physicsScene->activePlayer = 2;
			else
				m_physicsScene->activePlayer = 1;
		}

		m_physicsScene->canSwitch = false;
		m_physicsScene->potted = false;
	}

	
}

void PhysicsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();
	setBackgroundColour(0.3, 0.6, 0.3);
	
	m_2dRenderer->setCameraPos(0, 0);

	// begin drawing sprites
	m_2dRenderer->begin();

	// Render a simple sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);

	//m_2dRenderer->drawSprite(m_poolTable, 0, 0, 1570, 870);

	m_physicsScene->Draw();

	// OutPut Winner
	int x = getWindowWidth() * 0.1f;
	int y = getWindowHeight() * 0.94f;


	if (m_physicsScene->eightBallPotted)
	{
		m_2dRenderer->drawText(m_font, m_physicsScene->winnerStr.c_str(), x, y);
	}
	else if (m_physicsScene->canSwitch)
	{
		m_2dRenderer->drawText(m_font, "Waiting...", x, y);
	}
	else if (m_physicsScene->activePlayer == 1)
	{
		m_2dRenderer->drawText(m_font, "Player 1's Turn", x, y);
		
		if (m_physicsScene->p1OnRed == 1)
		{
			if (m_physicsScene->redsPotted == 7)
				m_2dRenderer->drawText(m_font, "8 BALL", x * 3.3f, y);
			else
				m_2dRenderer->drawText(m_font, "RED", x * 3.3f, y);
		}
		
		else if (m_physicsScene->p1OnRed == 0)
		{
			if (m_physicsScene->yellowsPotted == 7)
				m_2dRenderer->drawText(m_font, "8 BALL", x * 3.3f, y);
			else
				m_2dRenderer->drawText(m_font, "YELLOW", x * 3.3f, y);
		}

		else if (m_physicsScene->p1OnRed == 2)
			m_2dRenderer->drawText(m_font, "ANY COLOR", x * 3.3f, y);
	}
	else if (m_physicsScene->activePlayer == 2)
	{
		m_2dRenderer->drawText(m_font, "Player 2's Turn", x, y);

		if (m_physicsScene->p1OnRed == 1)
		{
			if (m_physicsScene->yellowsPotted == 7)
				m_2dRenderer->drawText(m_font, "8 BALL", x * 3.3f, y);
			else
				m_2dRenderer->drawText(m_font, "YELLOW", x * 3.3f, y);
		}
			

		else if (m_physicsScene->p1OnRed == 0)
		{
			if (m_physicsScene->redsPotted == 7)
				m_2dRenderer->drawText(m_font, "8 BALL", x * 3.3f, y);
			else
				m_2dRenderer->drawText(m_font, "RED", x * 3.3f, y);
		}
			
		else if (m_physicsScene->p1OnRed == 2)
			m_2dRenderer->drawText(m_font, "ANY COLOR", x * 3.3f, y);
	}

	aie::Gizmos::draw2D(glm::ortho<float>(-m_extents, m_extents, -m_extents / m_aspectRatio, m_extents / m_aspectRatio, -1.0f, 1.0f));

	m_2dRenderer->end();
}

void PhysicsApp::Pocket(PhysicsObject* other)
{
	Circle* ball = dynamic_cast<Circle*>(other);
	if (ball != nullptr)
	{
		CueBall* cueBall = dynamic_cast<CueBall*>(other);
		if (cueBall != nullptr)
		{
			m_physicsScene->needsRespawn = true;
			m_cueBall->SetPosition(glm::vec2(1000));
			m_cueBall->SetVelocity(glm::vec2(0));
		}
		else
		{
			ball->KillBall();
		}
	}
}

glm::vec2 PhysicsApp::ScreenToWorld(glm::vec2 screenPos)
{
	glm::vec2 worldPos = screenPos;

	// move the centre of the screen to (0,0)
	worldPos.x -= getWindowWidth() / 2;
	worldPos.y -= getWindowHeight() / 2;

	// scale according to our extents
	worldPos.x *= 2.0f * m_extents / getWindowWidth();
	worldPos.y *= 2.0f * m_extents / (m_aspectRatio * getWindowHeight());

	return worldPos;
}
