#pragma once
#include "PhysicsObject.h"
#include "RigidBody.h"

class Spring : public PhysicsObject
{
public:
	Spring(RigidBody* body1, RigidBody* body2,
		float springCoefficient, float damping, float restLength=0, glm::vec4 color=glm::vec4(1, 1, 1, 1),
		glm::vec2 contact1 = glm::vec2(0, 0), glm::vec2 contact2 = glm::vec2(0, 0));

	virtual void FixedUpdate(glm::vec2 gravity, float timeStep);
	virtual void Draw(float alpha);
	virtual void ResetPosition();
	virtual float GetEnergy();
	virtual bool IsInside(glm::vec2 worldPos);

	glm::vec2 GetContact1(float alpha=1);
	glm::vec2 GetContact2(float alpha=1);

protected:
	RigidBody* m_body1;
	RigidBody* m_body2;

	glm::vec2 m_contact1;
	glm::vec2 m_contact2;

	glm::vec4 m_color;

	float m_damping;
	float m_restLength;
	float m_springCoefficient;		// the restoring force;
};