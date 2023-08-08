//
// Created by bogdan on 06.08.2023.
//

#include "Physics.hpp"

Physics::Physics(double gravity)
    : m_force{0, 0}
    , m_gravity(gravity) {}

double Physics::getGravity(double deltaTime) const {
    return m_gravity * deltaTime;
}

void Physics::setGravity(const double gravity) {
    m_gravity = gravity;
}

amstl::vec2 Physics::getForce(double deltaTime) const {
    return {m_force.x * deltaTime, m_force.y * deltaTime};
}

void Physics::setForce(const amstl::vec2& force) {
    m_force = force;
}

void Physics::updateForce(const amstl::vec2& value) {
    m_force.x += value.x;
    m_force.y += value.y;
}


