//
// Created by bogdan on 06.08.2023.
//
#pragma once

#include <vector>
#include <glm/glm.hpp>
#include "Components/Rigidbody.hpp"

class Physics final {
public:
    Physics(): m_gravity(0), objects() {}
    Rigidbody* createObject(double mass, glm::vec2 position);
    void update(double deltaTime);
private:
    double m_gravity;
    std::vector<Rigidbody*> objects;
};
