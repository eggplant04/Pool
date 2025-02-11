#pragma once
#include "glm/vec2.hpp"
#include "vector"
#include "RigidBody.h"
#include <iostream>

class PhysicsObject;

class PhysicsScene
{
public:
    bool eightBallPotted = false;
    std::string winnerStr = "TEXT";

    bool needsRespawn = false;
    int redsPotted = 0;
    int yellowsPotted = 0;
    bool foul = false;
    bool potted = false;
    bool canSwitch = false;
    int activePlayer = 1;
    int p1OnRed = 2;
    bool groupsAssigned = false;

public:
    PhysicsScene();
    ~PhysicsScene();

    void AddActor(PhysicsObject* actor);
    void RemoveActor(PhysicsObject* actor);
    void Update(float dt);
    void Draw();
    void debugScene();
    static void ApplyContactForces(RigidBody* body1, RigidBody* body2, glm::vec2 norm, float pen);
    
    void CheckForRules();
    void CheckForCollision();

    void SetGravity(const glm::vec2 gravity) { m_gravity = gravity; }
    static glm::vec2 GetGravity() { return m_gravity; }

    void SetTimeStep(const float timeStep) { m_timeStep = timeStep; }
    float GetTimeStep() const { return m_timeStep; }

    float GetTotalEnergy();

    std::vector<PhysicsObject*> GetActors() { return m_actors; }

    static bool Plane2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
    static bool Plane2Circle(PhysicsObject* obj1, PhysicsObject* obj2);
    static bool Plane2Box(PhysicsObject* obj1, PhysicsObject* obj2);

    static bool Circle2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
    static bool Circle2Circle(PhysicsObject* obj1, PhysicsObject* obj2);
    static bool Circle2Box(PhysicsObject* obj1, PhysicsObject* obj2);

    static bool Box2Plane(PhysicsObject* obj1, PhysicsObject* obj2);
    static bool Box2Circle(PhysicsObject* obj1, PhysicsObject* obj2);
    static bool Box2Box(PhysicsObject* obj1, PhysicsObject* obj2);

protected:
    static glm::vec2 m_gravity;
    float m_timeStep;
    std::vector<PhysicsObject*> m_actors;
};

