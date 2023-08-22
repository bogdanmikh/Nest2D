//
// Created by bogdan on 06.08.2023.
//
#pragma once

#include <iostream>
#include "Physics.hpp"

void Physics::update(double deltaTime) {
    for (auto & object : objects) {
        if (object->m_canMove) {
            object->m_position = object->getNextPos(deltaTime, m_gravity);
        } else {
            object->m_position = object->getNextImpulsePos(deltaTime, m_gravity);
            object->m_force = object->m_impulse;
            object->m_impulse = {0, 0};
        }
        object->m_canMove = true;
        if (CollisionDetector::resolveCollisionCW(deltaTime, m_gravity, object)) {
            object->m_canMove = false;
            continue;
        }
        for (auto & otherObject : objects) {
            if (otherObject == object || otherObject->isTrigger()) continue;
            if (!CollisionDetector::canMoveCC(deltaTime, m_gravity, object, otherObject)) {
                object->m_canMove = false;
                CollisionDetector::resolveCollisionCC(deltaTime, m_gravity, object, otherObject);
                break;
            }
        }
    }
}

PhysicsObject* Physics::createObjectCircle(double mass, glm::vec2 position, double radius) {
    auto* object = new PhysicsObject(mass);
    object->createCircle(radius);
    object->m_position = position;
    objects.emplace_back(object);
    return object;
}

PhysicsObject* Physics::createObjectBox(double mass, glm::vec2 position, glm::vec2 size) {
    auto* object = new PhysicsObject(mass);
    object->createBox(size);
    object->m_position = position;
    objects.emplace_back(object);
    return object;
}
