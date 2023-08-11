//
// Created by bogdan on 06.08.2023.
//
#pragma once

#include "Physics.hpp"

void Physics::update(double deltaTime) {
    for (auto & object : objects) {
        object->m_position = {
                (object->getForce().x + object->m_position.x) * deltaTime,
                (object->getForce().y + m_gravity + object->m_position.y) * deltaTime
        };
    }
}

Rigidbody *Physics::createObject(double mass, glm::vec2 position) {
    Rigidbody* object = new Rigidbody(mass);
    object->m_position = position;
    objects.emplace_back(object);
    return object;
}

