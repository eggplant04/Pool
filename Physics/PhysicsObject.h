#pragma once
#include "glm/glm.hpp"
#include "glm/vec2.hpp"

enum ShapeType {
    JOINT = -1,
    PLANE = 0,
    CIRCLE,
    BOX
};

class PhysicsObject {
protected:
    PhysicsObject(ShapeType a_shapeID) : m_shapeID(a_shapeID), m_elasticity( 0.9 ) {}

public:
    virtual void FixedUpdate(glm::vec2 gravity, float timeStep) = 0;
    virtual void Draw(float alpha) = 0;
    virtual void ResetPosition() {};
    virtual float GetEnergy() = 0;
    virtual bool IsInside(glm::vec2 worldPos) = 0;

    int GetShapeID() { return m_shapeID; };
    
    float GetElasticity() { return m_elasticity; }
    void SetElasticity(float value) { m_elasticity = value; }

protected:
    ShapeType m_shapeID;
    float m_elasticity;
};