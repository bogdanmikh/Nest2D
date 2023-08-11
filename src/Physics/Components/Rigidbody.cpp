//
// Created by bogdan on 10.08.2023.
//

#include "Rigidbody.hpp"

Rigidbody::Rigidbody(double mass)
        : m_mass(mass)
        , m_position{0,0}
        , m_force{0, 0} {}

double Rigidbody::getMass() {
    return m_mass;
}

void Rigidbody::setMass(double mass) {
    m_mass = mass;
}

glm::vec2 Rigidbody::getForce() const {
    return m_force;
}

void Rigidbody::setForce(const glm::vec2& force) {
    m_force = force;
}