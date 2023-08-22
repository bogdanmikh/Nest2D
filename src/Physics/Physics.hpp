//
// Created by bogdan on 06.08.2023.
//
#pragma once

#include <vector>
#include <glm/glm.hpp>

#include "Components/PhysicsObject.hpp"
#include "CollisionDetector/CollisionDetector.hpp"

class Physics final {
public:
    Physics(): m_gravity(0), objects() {}
    PhysicsObject* createObjectCircle(double mass, glm::vec2 position, double radius);
    PhysicsObject* createObjectBox(double mass, glm::vec2 position, glm::vec2 size);
    void update(double deltaTime);
private:
    double m_gravity;
    std::vector<PhysicsObject*> objects;
};
