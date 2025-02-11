#pragma once
#include "Circle.h"
class Hole : public Circle
{
public:
	Hole(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color);
};

