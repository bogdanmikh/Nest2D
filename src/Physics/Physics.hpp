//
// Created by bogdan on 06.08.2023.
//
#pragma once

#include "../include/AMSTL/Vector2.hpp"

class Physics {
public:
    Physics(double gravity);
    double getGravity(double deltaTime) const;
    void setGravity(double gravity);
    amstl::vec2 getForce(double deltaTime) const;
    void setForce(const amstl::vec2& force);
    void updateForce(const amstl::vec2& value);
private:
    amstl::vec2 m_force;
    double m_gravity;
};

