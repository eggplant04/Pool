#pragma once
#include "Circle.h"
class CueBall : public Circle
{
public:
	CueBall(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color);

	void SetCanBeHit(bool state) { m_canBeHit = state; }
	bool GetCanBeHit() { return m_canBeHit; }

private:
	bool m_canBeHit;
};

