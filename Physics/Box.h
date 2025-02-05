#pragma once
#include "RigidBody.h"
class Box : public RigidBody
{
public:
    Box(glm::vec2 position, glm::vec2 velocity, float mass, glm::vec2 extents, float orientation, glm::vec4 color);
    ~Box();

    virtual void Draw(float alpha);

    virtual bool IsInside(glm::vec2 point);

    bool CheckBoxCorners(const Box& box, glm::vec2& contact, int& numContacts, float& pen, glm::vec2& edgeNormal);

    glm::vec2 GetExtents() { return m_extents; }
    float GetWidth() { return m_extents.x * 2; }
    float GetHeight() { return m_extents.y * 2; }

protected:
    glm::vec2 m_extents;			// the halfedge lengths 

    glm::vec4 m_color;
};