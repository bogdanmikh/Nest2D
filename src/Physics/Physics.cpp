//
// Created by bogdan on 06.08.2023.
//
#pragma once

#include "CollisionDetector/CollisionDetector.hpp"
#include "Physics.hpp"

void Physics::update(double deltaTime) {
    auto *collisionDetector = new CollisionDetector();
    for (auto & object : objects) {
        glm::vec2 nextPos = {
                (object->getForce().x * deltaTime + object->m_position.x),
                ((object->getForce().y + -m_gravity) * deltaTime + object->m_position.y)
        };
        bool canMove = true;
        for (auto & otherObject : objects) {
            if (otherObject == object) continue;
            const std::vector<glm::vec2> &polygonA = object->getVertex(nextPos);
            const std::vector<glm::vec2> &polygonB = otherObject->getVertex();
            if (collisionDetector->gjk(polygonA, polygonB)) {
                canMove = false;
                break;
            }
        }
        if (canMove) {
            object->m_position = nextPos;
        }
    }
    delete collisionDetector;
}

void Physics::dumpPolygon(const std::vector<glm::vec2> &polygonA) const {
    for (auto s : polygonA) {
        std::cout << '{' << s.x << ", " << s.y << '}';
    }
    std::cout << ";" << std::endl;
}

Rigidbody* Physics::createObject(double mass, glm::vec2 position) {
    auto* object = new Rigidbody(mass);
    object->m_position = position;
    objects.emplace_back(object);
    return object;
}

