#include "Hole.h"

Hole::Hole(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color)
	:Circle(position, velocity, mass, radius, color)
{
	m_isTrigger = true;
	m_isKinematic = true;
}
