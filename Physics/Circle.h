#pragma once
#include "RigidBody.h"
#include "glm/vec4.hpp"

class Circle : public RigidBody
{
public:
    Circle(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color);
    Circle(glm::vec2 position, float inclination, float velocity, float mass, float radius, glm::vec4 color);
    ~Circle();

    virtual void Draw(float alpha);
    virtual bool IsInside(glm::vec2 point);

    float GetRadius() { return m_radius; }
    glm::vec4 GetColor() { return m_color; }

protected:
    float m_radius;
    glm::vec4 m_color;
};

