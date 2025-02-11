#include "Circle.h"
#include "Gizmos.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

Circle::Circle(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color)
    : RigidBody(CIRCLE, position, velocity, 0, mass)
{
    m_radius = radius;
    m_color = color;
    m_moment = 0.5 * m_mass * (m_radius * m_radius);
}

Circle::Circle(glm::vec2 position, float inclination, float speed, float mass, float radius, glm::vec4 color)
    : RigidBody(CIRCLE, position, glm::vec2(speed* cos(inclination), speed* sin(inclination)), 0, mass)
{
    m_velocity = glm::vec2(speed * cos(inclination), speed * sin(inclination));
    m_radius = radius;
    m_color = color;
}

Circle::~Circle()
{
}

void Circle::Draw(float alpha)
{
    CalculateSmoothedPosition(alpha);

    aie::Gizmos::add2DCircle(m_smoothedPosition, m_radius, 30, m_color);
}

bool Circle::IsInside(glm::vec2 point)
{
    return glm::distance(point, m_position) <= m_radius;
}

