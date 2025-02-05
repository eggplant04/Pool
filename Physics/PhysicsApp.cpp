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

bool PhysicsApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	// increase the 2d line count to maximize the number of objects we can draw
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_font = new aie::Font("../bin/font/consolas.ttf", 32);
	m_poolTable = new aie::Texture("./textures/poolTable.png");

	// PhysicsScene =========
	m_physicsScene = new PhysicsScene();
	m_physicsScene->SetGravity(glm::vec2(0, -90));
	m_physicsScene->SetTimeStep(0.01);
	//=======================

	#pragma region  ------------03------------
	
	/*
	// simulate 2 balls colliding
	Circle* ball1 = new Circle(glm::vec2(-40, 0), glm::vec2(30, 0), 3.0f, 10, glm::vec4(1, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(40, 10), glm::vec2(-30, 0), 3.0f, 10, glm::vec4(0, 0, 1, 1));
	
	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	
	m_physicsScene->SetGravity(glm::vec2(0, -9.82f));

	Circle* ball1 = new Circle(glm::vec2(-20, 0), glm::vec2(0), 9.0f, 9, glm::vec4(1, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(10, 0), glm::vec2(0), 4.0f, 4, glm::vec4(0, 1, 0, 1));
	Plane* plane = new Plane(glm::vec2(0, 1), -30);

	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	m_physicsScene->AddActor(plane);
	*/

	#pragma endregion
	#pragma region  ------------03.1----------
	/*
	m_physicsScene->SetGravity(glm::vec2(0, -9.81));
	m_physicsScene->SetTimeStep(0.1f);

	float radius = 1.0f;
	float speed = 30;
	glm::vec2 startPos(-40, 0);
	float inclination = glm::radians(45.f);		// 45 degrees

	m_physicsScene->AddActor(new Circle(startPos, inclination, speed, 1, radius, glm::vec4(1, 0, 0, 1)));

	SetupConinuousDemo(glm::vec2(-40, 0), 45.f, 30.f, 9.8f);
	*/
	#pragma endregion
	#pragma region  ------------04------------
	/*
	// billard ball simulation
	Circle* ball1 = new Circle(glm::vec2(40, 0), glm::vec2(-40, 0), 17.f, 5, glm::vec4(0, 1, 1, 1));
	Circle* ball2 = new Circle(glm::vec2(-40, 8), glm::vec2(0, 0), 16.f, 5, glm::vec4(1, 0, 0, 1));

	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	
    // balls in a bowl
	m_physicsScene->SetGravity(glm::vec2(0, -90.81f));

	Circle* ball1 = new Circle(glm::vec2(0, 0), glm::vec2(0, -10), 16, 5, glm::vec4(1, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(0, 0), glm::vec2(0, -30), 16, 5, glm::vec4(1, 0, 0, 1));
	Circle* ball3 = new Circle(glm::vec2(0, 0), glm::vec2(0, 20), 16, 5, glm::vec4(1, 0, 0, 1));

	Plane* planeL = new Plane(glm::vec2(0.5, 1), -30);
	Plane* planeR = new Plane(glm::vec2(-0.5, 1), -30);

	m_physicsScene->AddActor(ball1); 
	m_physicsScene->AddActor(ball2); 
	m_physicsScene->AddActor(ball3);
	m_physicsScene->AddActor(planeL);
	m_physicsScene->AddActor(planeR);
	
	// Symmetrical Newton’s Cradle
	m_physicsScene->SetGravity(glm::vec2(0, 0));

	Circle* ball1 = new Circle(glm::vec2(0, 0), glm::vec2(0, 0), 16, 5, glm::vec4(1, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(-20, 0), glm::vec2(-100, 0), 16, 5, glm::vec4(1, 0, 0, 1));
	Circle* ball3 = new Circle(glm::vec2(-10, 0), glm::vec2(0, 0), 16, 5, glm::vec4(1, 0, 0, 1));
	Circle* ball4 = new Circle(glm::vec2(10, 0), glm::vec2(0, 0), 30, 5, glm::vec4(1, 1, 0, 1));
	Circle* ball5 = new Circle(glm::vec2(20, 0), glm::vec2(0, 0), 16, 5, glm::vec4(1, 0, 0, 1));

	Plane* planeL = new Plane(glm::vec2(1, 0), -60);
	Plane* planeR = new Plane(glm::vec2(-1, 0), -60);

	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	m_physicsScene->AddActor(ball3);
	m_physicsScene->AddActor(ball4);
	m_physicsScene->AddActor(ball5);
	m_physicsScene->AddActor(planeL);
	m_physicsScene->AddActor(planeR);
    */
	#pragma endregion
	#pragma region  ------------05------------
	
	/*
	// Box
	m_physicsScene->SetGravity(glm::vec2(0, -90));
	Box* box1 = new Box(glm::vec2(-10, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0.2f, glm::vec4(1, 0, 0, 1));
	Box* box2 = new Box(glm::vec2(-20, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0, glm::vec4(1, 0, 0, 1));
	Box* box3 = new Box(glm::vec2(-30, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0.2f, glm::vec4(1, 0, 0, 1));
	Box* box4 = new Box(glm::vec2(-40, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0, glm::vec4(1, 0, 0, 1));
	Box* box5 = new Box(glm::vec2(-50, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0.2f, glm::vec4(1, 0, 0, 1));
	Box* box6 = new Box(glm::vec2(-60, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0, glm::vec4(1, 0, 0, 1));

	Circle* ball = new Circle(glm::vec2(10, 0), glm::vec2(100), 16.0f, 5, glm::vec4(1, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(9, 30), glm::vec2(100), 16.0f, 5, glm::vec4(1, 0, 0, 1));


	m_physicsScene->AddActor(box1);
	m_physicsScene->AddActor(box2);
	m_physicsScene->AddActor(box3);
	m_physicsScene->AddActor(box4);
	m_physicsScene->AddActor(box5);
	m_physicsScene->AddActor(box6);

	m_physicsScene->AddActor(ball);
	m_physicsScene->AddActor(ball2);

	Plane* plane1 = new Plane(glm::vec2(0, 1), -56.5);
	Plane* plane2 = new Plane(glm::vec2(0, -1), -56.5);
	Plane* plane3 = new Plane(glm::vec2(1, 0), -100);
	Plane* plane4 = new Plane(glm::vec2(-1, 0), -100.1);
	m_physicsScene->AddActor(plane1);
	m_physicsScene->AddActor(plane2);
	m_physicsScene->AddActor(plane3);
	m_physicsScene->AddActor(plane4);
	*/

	#pragma endregion
	#pragma region  ------------06------------
	/*
	// POOL TABLE

	// Cue ball
	cueBall = new Circle(glm::vec2(-50, 0), glm::vec2(0, 0), 16.0f, 4, glm::vec4(0.8, 0.8, 0.8, 1));
	m_physicsScene->AddActor(cueBall);
	
	// Billard balls
	Circle* ball1 = new Circle(glm::vec2(50, 0), glm::vec2(0), 17.0f, 4, glm::vec4(0, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(43, 4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball3 = new Circle(glm::vec2(43, -4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball4 = new Circle(glm::vec2(36, 0), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball5 = new Circle(glm::vec2(57, 4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball6 = new Circle(glm::vec2(57, -4), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball7 = new Circle(glm::vec2(50, -8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball8 = new Circle(glm::vec2(50, 8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball9 = new Circle(glm::vec2(57, -12), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball10 = new Circle(glm::vec2(57, 12), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball11 = new Circle(glm::vec2(64, 0), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball12 = new Circle(glm::vec2(64, 8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball13 = new Circle(glm::vec2(64, 16), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball14 = new Circle(glm::vec2(64, -8), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball15 = new Circle(glm::vec2(64, -16), glm::vec2(0), 17.0f, 4, glm::vec4(1, 0, 0, 1));

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

	// Table
	Plane* plane1 = new Plane(glm::vec2(0, 1), -44);
	Plane* plane2 = new Plane(glm::vec2(0, -1), -44);
	Plane* plane3 = new Plane(glm::vec2(1, 0), -88);
	Plane* plane4 = new Plane(glm::vec2(-1, 0), -88);
	m_physicsScene->AddActor(plane1);
	m_physicsScene->AddActor(plane2);
	m_physicsScene->AddActor(plane3);
	m_physicsScene->AddActor(plane4);
	*/
	#pragma endregion
	#pragma region  ------------NINE----------
	
/*
	m_physicsScene->SetGravity(glm::vec2(0, -90));
	
	Circle* ball1 = new Circle(glm::vec2(0, 0), glm::vec2(0), 17.0f, 1, glm::vec4(1, 1, 1, 1));
	ball1->SetKinematic(true);
	Circle* ball2 = new Circle(glm::vec2(12, 20), glm::vec2(0), 17.0f, 1, glm::vec4(1, 1, 1, 1));

	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);

	Spring* rope = new Spring(ball1, ball2, 1000, 1, glm::vec4(1, 1, 1, 1), 30.f);
	m_physicsScene->AddActor(rope);
	
	Circle* prev = nullptr;
	for (int i = 0; i < 5; i++)
	{
		// spawn a circle to the right and below the previous one, so that the whole rope acts under gravity and swings
		Circle* circle = new Circle(glm::vec2(i * 3, 30 - i * 5), glm::vec2(0), 10, 2, glm::vec4(1, 1, 1, 1));
		if (i == 0)
			circle->SetKinematic(true);
		m_physicsScene->AddActor(circle);
		if (prev)
			m_physicsScene->AddActor(new Spring(circle, prev, 500, 10, 7));
		prev = circle;
	}

	// add a kinematic box at an angle for the rope to drape over
	Box* box1 = new Box(glm::vec2(-10, 0), glm::vec2(100), 16.0f, glm::vec2(5, 5), 0.2f, glm::vec4(1, 0, 0, 1));
	box1->SetKinematic(true);
	m_physicsScene->AddActor(box1);

	// Table
	Plane* plane1 = new Plane(glm::vec2(0, 1), -44);
	Plane* plane2 = new Plane(glm::vec2(0, -1), -44);
	Plane* plane3 = new Plane(glm::vec2(1, 0), -88);
	Plane* plane4 = new Plane(glm::vec2(-1, 0), -88);
	m_physicsScene->AddActor(plane1);
	m_physicsScene->AddActor(plane2);
	m_physicsScene->AddActor(plane3);
	m_physicsScene->AddActor(plane4);
*/
	#pragma endregion
	#pragma region  ------------10------------
	/*
	moveobj = new Circle(glm::vec2(-50, 0), glm::vec2(0), 16, 5, glm::vec4(0, 1, 1, 1));
	m_physicsScene->AddActor(moveobj);
	// softbody name
	std::vector<std::string> sb;
	sb.push_back("000000");
	sb.push_back("000000");
	sb.push_back("000000");
	sb.push_back("000000");
	sb.push_back("000000");
	sb.push_back("000000");

	SoftBody::Build(m_physicsScene, glm::vec2(0, 0), 500.0f, 10.0f, 4.f, sb);

	// Table
	Plane* plane1 = new Plane(glm::vec2(0, 1), -44);
	Plane* plane2 = new Plane(glm::vec2(0, -1), -44);
	Plane* plane3 = new Plane(glm::vec2(1, 0), -88);
	Plane* plane4 = new Plane(glm::vec2(-1, 0), -88);
	m_physicsScene->AddActor(plane1);
	m_physicsScene->AddActor(plane2);
	m_physicsScene->AddActor(plane3);
	m_physicsScene->AddActor(plane4);
	*/
	#pragma endregion

	

	return true;
}

void PhysicsApp::shutdown() 
{
	delete m_font;
	delete m_2dRenderer;
}

void PhysicsApp::update(float deltaTime) 
{
	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();
	
	m_physicsScene->Update(deltaTime);
	
	if (input->isMouseButtonDown(0))
	{
		int xScreen, yScreen;
		input->getMouseXY(&xScreen, &yScreen);
		glm::vec2 worldPos = ScreenToWorld(glm::vec2(xScreen, yScreen));

		aie::Gizmos::add2DCircle(worldPos, 5, 32, glm::vec4(0, 0, 1, 1));
	}

	// shoot ball
	//if (input->isKeyDown(aie::INPUT_KEY_SPACE) && cueBall->GetVelocity() == glm::vec2(0))
	//	cueBall->ApplyForce(glm::vec2(cos(cueBall->GetOrientatation()) * 5000, sin(cueBall->GetOrientatation()) * 5000));
	//
	//// aim left
	//if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A))
	//	cueBall->SetOrientation(cueBall->GetOrientatation() + 0.1f);
	//
	//if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D))
	//	cueBall->SetOrientation(cueBall->GetOrientatation() + -0.1f);

	// -------------------------------------------------------------------------------
	//if (input->isKeyDown(aie::INPUT_KEY_W))
	//	moveobj->ApplyForce(glm::vec2(0, 100));
	//
	//if (input->isKeyDown(aie::INPUT_KEY_S))
	//	moveobj->ApplyForce(glm::vec2(0, -100));
	//
	//// aim left
	//if (input->isKeyDown(aie::INPUT_KEY_A) || input->isKeyDown(aie::INPUT_KEY_A))
	//	moveobj->ApplyForce(glm::vec2(-100, 0));
	//
	//if (input->isKeyDown(aie::INPUT_KEY_D) || input->isKeyDown(aie::INPUT_KEY_D))
	//	moveobj->ApplyForce(glm::vec2(100, 0));


}

void PhysicsApp::draw() {

	// wipe the screen to the background colour
	clearScreen();
	setBackgroundColour(0.3, 0.5, 0.3);
	
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// Render a simple sprite
	m_2dRenderer->setUVRect(0, 0, 1, 1);
	//m_2dRenderer->drawSprite(m_poolTable, 200, 200, 100, 100);

	m_physicsScene->Draw();
	
	// output fps 
	std::string fpsString = std::to_string(getFPS());
	m_2dRenderer->drawText(m_font, "FPS: ", 15, 30);
	m_2dRenderer->drawText(m_font, fpsString.c_str(), 100, 30);

	static float aspectRatio = 16.f / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-m_extents, m_extents, -m_extents / m_aspectRatio, m_extents / m_aspectRatio, -1.0f, 1.0f));

	m_2dRenderer->end();
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
