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
	#pragma region  ------------11------------
	/*
	m_physicsScene->SetGravity(glm::vec2(0, -9.82f));
	
	Circle* ball1 = new Circle(glm::vec2(-20, 0), glm::vec2(0), 4.0f, 4, glm::vec4(1, 0, 0, 1));
	Circle* ball2 = new Circle(glm::vec2(10, -20), glm::vec2(0), 4.0f, 4, glm::vec4(0, 1, 0, 1));
	ball2->SetKinematic(true);
	ball2->SetTrigger(true);
	
	m_physicsScene->AddActor(ball1);
	m_physicsScene->AddActor(ball2);
	m_physicsScene->AddActor(new Plane(glm::vec2(0, 1), -30));
	m_physicsScene->AddActor(new Plane(glm::vec2(1, 0), -50));
	m_physicsScene->AddActor(new Plane(glm::vec2(-1, 0), -50));
	m_physicsScene->AddActor(new Box(glm::vec2(20, 10), glm::vec2(3, 0), 0.5f, glm::vec2({ 4, 8 }), 4.f, glm::vec4(1, 1, 0, 1)));
	m_physicsScene->AddActor(new Box(glm::vec2(-40, 10), glm::vec2(10, 0), 30.f, glm::vec2({ 4, 8 }), 4.f, glm::vec4(1, 0, 2, 1)));
	
	ball1->collisionCallback = [=](PhysicsObject* other) 
		{
		if (other == ball2)
		{
			std::cout << "Howzat!!?" << std::endl;
		}
		return;
	};
	
	ball2->collisionCallback = std::bind(&PhysicsApp::OnBall2Check, this, std::placeholders::_1);

	ball2->triggerEnter = [=](PhysicsObject* other) { std::cout << "Enter:" << other << std::endl; };
	ball2->triggerExit = [=](PhysicsObject* other) { std::cout << "Exit:" << other << std::endl; };
	*/
	#pragma endregion

	// POOL TABLE
	m_physicsScene->SetGravity(glm::vec2(0));
	
	// Cue ball
	m_cueBall = new CueBall(glm::vec2(-50, 0), glm::vec2(0, 0), 18.0f, 4, glm::vec4(0.8, 0.8, 0.8, 1));
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
	Hole* hole1 = new Hole(glm::vec2(0, -44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole2 = new Hole(glm::vec2(88, -44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole3 = new Hole(glm::vec2(-88, -44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
	Hole* hole4 = new Hole(glm::vec2(0, 44), glm::vec2(0), 17.0f, 5, glm::vec4(0, 0, 0, 1));
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
	// input example
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();
	
	m_physicsScene->Update(deltaTime);
	
	if (input->isMouseButtonDown(0))
	{
		m_cueBall->SetCanBeHit(true);
		int xScreen, yScreen;
		input->getMouseXY(&xScreen, &yScreen);
		glm::vec2 worldPos = ScreenToWorld(glm::vec2(xScreen, yScreen));
		float dist = glm::distance(m_cueBall->GetPosition(), worldPos);
		glm::vec2 forceDir = m_cueBall->GetPosition() - worldPos; // Direction from mouse to ball
		if (glm::length(forceDir) > 0) {
			forceDir = glm::normalize(forceDir);
		}

		
		float forceMagnitude = 100.f;
		m_cueForce = forceDir * dist;

		aie::Gizmos::add2DLine(glm::vec2(worldPos), m_cueBall->GetPosition(), glm::vec4(1, 0, 0, 1));
	}
	if (input->isMouseButtonUp(0) && m_cueBall->GetCanBeHit())
	{
		m_cueBall->SetCanBeHit(false);
		m_cueBall->ApplyForce(m_cueForce * 100.f);
	}
	

	// shoot ball
	if (input->isKeyDown(aie::INPUT_KEY_SPACE) && m_physicsScene->GetTotalEnergy() == 0.f)
	{
		m_physicsScene->canSwitch = true;
		m_cueBall->ApplyForce(glm::vec2(cos(m_cueBall->GetOrientatation()) * 2000, sin(m_cueBall->GetOrientatation()) * 2000));
	}

	if (m_physicsScene->GetTotalEnergy() == 0.f)
	{
		if (m_physicsScene->canSwitch && !m_physicsScene->potted)
		{
			if (m_physicsScene->activePlayer == 1)
				m_physicsScene->activePlayer = 2;
			else
				m_physicsScene->activePlayer = 1;
		}
		
		m_physicsScene->canSwitch = false;
		m_physicsScene->potted = false;
	}

	
	// aim left
	if (input->isKeyDown(aie::INPUT_KEY_LEFT) || input->isKeyDown(aie::INPUT_KEY_A))
		m_cueBall->SetOrientation(m_cueBall->GetOrientatation() + 0.1f);
	
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT) || input->isKeyDown(aie::INPUT_KEY_D))
		m_cueBall->SetOrientation(m_cueBall->GetOrientatation() + -0.1f);
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
	
	// output Active Player
	if (m_physicsScene->canSwitch)
	{
		m_2dRenderer->drawText(m_font, "Waiting...", 100, 680);
	}
	else if (m_physicsScene->activePlayer == 1)
	{
		m_2dRenderer->drawText(m_font, "Player 1's Turn", 100, 680);
		
		if (m_physicsScene->p1OnRed == 1)
			m_2dRenderer->drawText(m_font, "RED", 400, 680);
		
		else if (m_physicsScene->p1OnRed == 0)
			m_2dRenderer->drawText(m_font, "YELLOW", 400, 680);

		else if (m_physicsScene->p1OnRed == 2)
			m_2dRenderer->drawText(m_font, "ANY COLOR", 400, 680);
	}
	else if (m_physicsScene->activePlayer == 2)
	{
		m_2dRenderer->drawText(m_font, "Player 2's Turn", 100, 680);

		if (m_physicsScene->p1OnRed == 1)
			m_2dRenderer->drawText(m_font, "YELLOW", 400, 680);

		else if (m_physicsScene->p1OnRed == 0)
			m_2dRenderer->drawText(m_font, "RED", 400, 680);

		else if (m_physicsScene->p1OnRed == 2)
			m_2dRenderer->drawText(m_font, "ANY COLOR", 400, 680);
	}
		

	// output fps 
	std::string fpsString = std::to_string(getFPS());
	m_2dRenderer->drawText(m_font, "FPS: ", 100, 30);
	m_2dRenderer->drawText(m_font, fpsString.c_str(), 185, 30);

	aie::Gizmos::draw2D(glm::ortho<float>(-m_extents, m_extents, -m_extents / m_aspectRatio, m_extents / m_aspectRatio, -1.0f, 1.0f));

	m_2dRenderer->end();
}

void PhysicsApp::Pocket(PhysicsObject* other)
{
	Circle* ball = dynamic_cast<Circle*>(other);
	if (ball != nullptr)
	{
		ball->KillBall();
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
