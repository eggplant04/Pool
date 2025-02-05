#pragma once
#include "PhysicsScene.h"
#include "glm/vec2.hpp"
#include "iostream"
#include "Circle.h"
#include "Spring.h"
#include <glm/glm.hpp>
#include "Box.h"

class SoftBody
{
public:
	static void Build(PhysicsScene* scene, glm::vec2 position, float damping, float springForce, float spacing, std::vector<std::string>& strings);
};

