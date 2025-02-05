#include "Plane.h"
#include "glm/glm.hpp"
#include "Gizmos.h"
#include "glm/gtc/matrix_transform.hpp"
#include "PhysicsScene.h"
#include "Circle.h"
Plane::Plane(glm::vec2 normal, float distance)
	: PhysicsObject(PLANE)
{
	m_normal = glm::normalize(normal);
    m_color = glm::vec4(0.4, 0.4, 0.4, 1);
    m_distanceToOrigin = distance;
}

Plane::~Plane()
{
}

void Plane::FixedUpdate(glm::vec2 gravity, float timeStep)
{
}

void Plane::Draw(float alpha)
{
    float lineSegmentLength = 300;
    glm::vec2 centerPoint = m_normal * m_distanceToOrigin;
    // easy to rotate normal through 90 degrees around z
    glm::vec2 parallel(m_normal.y, -m_normal.x);
    glm::vec4 colorFade = m_color;
    colorFade.a = 0;
    glm::vec2 start = centerPoint + (parallel * lineSegmentLength);
    glm::vec2 end = centerPoint - (parallel * lineSegmentLength);
    
    aie::Gizmos::add2DLine(start, end, glm::vec4(1, 1, 1, 1));
    aie::Gizmos::add2DTri(start, end, start - m_normal * 10.0f, m_color, m_color, colorFade);
    aie::Gizmos::add2DTri(end, end - m_normal * 10.0f, start - m_normal * 10.0f, m_color, colorFade, colorFade);
}

void Plane::ResetPosition()
{
    m_distanceToOrigin = 0.f;
}

float Plane::GetEnergy()
{
    return 0.0f;
}

void Plane::ResolveCollision(RigidBody* actor2, glm::vec2 contact)
{
	// the position at which we'll apply the force relative to the object's COM
	glm::vec2 localContact = contact - actor2->GetPosition();

	// the plane isn't moving, so the relative velocity is just actor2's velocity at the contact point
	glm::vec2 vRel = actor2->GetVelocity() + actor2->GetAngularVelocity() * glm::vec2(-localContact.y, localContact.x);
	float velocityIntoPlane = glm::dot(vRel, m_normal);

	// perfectly elasticity collisions for now
	float elasticity = (GetElasticity() + actor2->GetElasticity()) / 2.0f;

	// this is the perpendicular distance we apply the force at relative to the COM, so Torque = F*r
	float r = glm::dot(localContact, glm::vec2(m_normal.y, -m_normal.x));

	// work out the "effective mass" - this is a combination of moment of
	// inertia and mass, and tells us how much the contact point velocity 
	// will change with the force we're applying
	float mass0 = 1.0f / (1.0f / actor2->GetMass() + (r * r) / actor2->GetMoment());

	float j = -(1 + elasticity) * velocityIntoPlane * mass0;

	glm::vec2 force = m_normal * j;

	actor2->ApplyForce(force, contact - actor2->GetPosition());

	float pen = glm::dot(contact, m_normal) - m_distanceToOrigin;

	Circle* circle = dynamic_cast<Circle*>(actor2);
	if (circle != nullptr)
	{
		pen -= circle->GetRadius();
	}
	PhysicsScene::ApplyContactForces(actor2, nullptr, m_normal, pen);
}
