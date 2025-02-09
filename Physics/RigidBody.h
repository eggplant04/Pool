#pragma once
#include "PhysicsObject.h"
#include <functional>

class RigidBody : public PhysicsObject 
{
public:
    RigidBody(ShapeType shapeID, glm::vec2 position,
        glm::vec2 velocity, float orientation, float mass);
    ~RigidBody();

    virtual void FixedUpdate(glm::vec2 gravity, float timeStep);
    void ApplyForce(glm::vec2 force, glm::vec2 position);
    void ApplyForce(glm::vec2 force);
    
    std::function<void(PhysicsObject*)> collisionCallback;

    void ResolveCollision(RigidBody* actor2, glm::vec2 contact,
        glm::vec2* collisionNormal=nullptr, float pen=0);

    void CalculateSmoothedPosition(float alpha);

    void CalculateAxes();

    glm::vec2 ToWorld(glm::vec2 position, float alpha);

    // gets and sets
    float GetKineticEnergy();
    float GetPotentialEnergy();
    float GetEnergy() override;

    void SetVelocity(glm::vec2 force) { m_velocity = force; }

    glm::vec2 GetPosition() const { return m_position; }
    void SetPosition(glm::vec2 position) { m_position = position; }
    glm::vec2 GetVelocity() { return m_velocity; }

    float GetOrientatation() { return m_orientation; }
    void SetOrientation(float value) { m_orientation = value; }

    float GetAngularVelocity() { return m_angularVelocity; }

    float GetMass() { return m_isKinematic ? INT_MAX : m_mass; }
    float GetMoment() { return m_isKinematic ? INT_MAX : m_moment; }

    glm::vec2 GetLocalX() { return m_localX; }
    glm::vec2 GetLocalY() { return m_localY; }

    float GetAngularDrag() { return m_angularDrag; }
    void SetAngularDrag(float value) { m_angularDrag = value; }

    float GetLinearDrag() { return m_linearDrag; }
    void SetLinearDrag(float value) { m_linearDrag = value; }

    void SetKinematic(bool state) { m_isKinematic = state; }
    bool IsKinematic() { return m_isKinematic; }

protected:
    glm::vec2 m_position;
    glm::vec2 m_lastPosition;
    glm::vec2 m_velocity;
    float m_mass;
    float m_orientation;
    float m_angularVelocity;
    float m_moment;

    float m_lastOrientation;

    glm::vec2 m_localX;
    glm::vec2 m_localY;

    glm::vec2 m_smoothedPosition;
    glm::vec2 m_smoothedLocalX;
    glm::vec2 m_smoothedLocalY;

    float m_linearDrag; // Between 0 and 1
    float m_angularDrag; // Between 0 and 1

    bool m_isKinematic;
};

