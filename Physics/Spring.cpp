#include "Spring.h"
#include "Gizmos.h"

Spring::Spring(RigidBody* body1, RigidBody* body2, 
	float springCoefficient, float damping, float restLength, glm::vec4 color, 
	glm::vec2 contact1, glm::vec2 contact2)

	: PhysicsObject(PLANE), 
	m_body1(body1), m_body2(body2), 
	m_springCoefficient(springCoefficient), m_damping(damping), m_color(color), m_restLength(restLength), 
	m_contact1(contact1), m_contact2(contact2)
{
	if (restLength == 0)
	{
		if (m_body1) m_body1->CalculateAxes();
		if (m_body2) m_body2->CalculateAxes();
		m_restLength = glm::distance(GetContact1(), GetContact2());
	}
}

void Spring::FixedUpdate(glm::vec2 gravity, float timeStep)
{
	// Get the world coordinates of the ends of the springs
	glm::vec2 p1 = GetContact1();
	glm::vec2 p2 = GetContact2();

	float length = glm::distance(p1, p2);
	glm::vec2 direction = glm::normalize(p2 - p1);

	// apply damping
	glm::vec2 relativeVelocity = m_body2->GetVelocity() - m_body1->GetVelocity();

	// F = -kX - bv
	glm::vec2 force = direction * m_springCoefficient * (m_restLength - length) - m_damping * relativeVelocity;
	
	// cap the spring force to 1000 N to prevent numerical instability
	const float threshold = 1000.0f;
	float forceMag = glm::length(force);

	if (forceMag > threshold)
		force *= threshold / forceMag;

	m_body1->ApplyForce(-force * timeStep, p1 - m_body1->GetPosition());
	m_body2->ApplyForce(force * timeStep, p2 - m_body2->GetPosition());
}

void Spring::Draw(float alpha)
{
	aie::Gizmos::add2DLine(GetContact1(alpha), GetContact2(alpha), m_color);
}

void Spring::ResetPosition()
{
}

float Spring::GetEnergy()
{
	return 0.0f;
}

bool Spring::IsInside(glm::vec2 worldPos)
{
	return false;
}

glm::vec2 Spring::GetContact1(float alpha)
{
	return m_body1 ? m_body1->ToWorld(m_contact1, alpha) : m_contact1;
}

glm::vec2 Spring::GetContact2(float alpha)
{
	return m_body2 ? m_body2->ToWorld(m_contact2, alpha) : m_contact2;
}
