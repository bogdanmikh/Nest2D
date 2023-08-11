//
// Created by bogdan on 10.08.2023.
//
#pragma once

#include <glm/vec2.hpp>

// Forward declaration
class Physics;

class Rigidbody final {
public:
    explicit Rigidbody(double mass);
    double getMass();
    void setMass(double mass);

    glm::vec2 getForce() const;
    void setForce(const glm::vec2& force);

    inline glm::vec2 getPosition() const {
        return m_position;
    }
private:
    glm::vec2 m_position;
    glm::vec2 m_force;
    double m_mass;

    friend class Physics;
};
