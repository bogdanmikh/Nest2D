//
// Created by bogdan on 19.08.2023.
//

#pragma once

#include <iostream>
#include "CollisionDetector.hpp"

bool CollisionDetector::canMoveCC(double deltaTime, double gravity,
                                const PhysicsObject* ph1, const PhysicsObject* ph2) {
    glm::vec2 vecPos = {
            ph1->getNextPos(deltaTime, gravity).x - ph2->getNextPos(deltaTime, gravity).x,
            ph1->getNextPos(deltaTime, gravity).y - ph2->getPosition().y
    };
    double distance = std::sqrt(std::abs(vecPos.x * vecPos.x + vecPos.y * vecPos.y));
    return distance >= ph1->getCircleCollider()->getRadius() + ph1->getCircleCollider()->getRadius();
}

bool CollisionDetector::canMoveBB(double deltaTime, double gravity, const PhysicsObject *ph1,
                                  const PhysicsObject *ph2) {
    return false;
}

bool CollisionDetector::canMoveBC(double deltaTime, double gravity, const PhysicsObject *ph1,
                                  const PhysicsObject *ph2) {
    return false;
}

glm::vec2 normalize(const glm::vec2& v) {
    double length = std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2));
    return {v.x / length, v.y / length};
}

void CollisionDetector::resolveCollisionCC(double deltaTime, double gravity, PhysicsObject *ph1, PhysicsObject *ph2) {

    // Вычисляем вектор разности позиций центров кругов
    glm::vec2 difference = {ph2->getNextPos(deltaTime, gravity).x - ph1->getNextPos(deltaTime, gravity).x, ph2->getNextPos(deltaTime, gravity).y - ph1->getNextPos(deltaTime, gravity).y};
    glm::vec2 normal = normalize(difference);

    // Вычисляем вектор отскока
    glm::vec2 relativeVelocity = ph2->getForce() - ph1->getForce();
    double velocityAlongNormal = glm::dot(relativeVelocity, normal);
    glm::vec2 impulse = normal * static_cast<float>(velocityAlongNormal);

    // Распределение импульса силы на два круга, пропорционально их массам
    double totalMass = ph1->getMass() + ph2->getMass();
    double circle1Factor = 2.0 * ph2->getMass() / totalMass;
    double circle2Factor = 2.0 * ph1->getMass() / totalMass;

    ph1->setImpulse(impulse * static_cast<float>(circle1Factor));
    ph2->setImpulse(impulse * static_cast<float>(-circle2Factor));
}

void CollisionDetector::resolveCollisionBB(double deltaTime, double gravity, PhysicsObject *ph1,
                                           PhysicsObject *ph2) {

}

void CollisionDetector::resolveCollisionBC(double deltaTime, double gravity, PhysicsObject *ph1,
                                           PhysicsObject *ph2) {

}

bool CollisionDetector::resolveCollisionCW(double deltaTime,
                                           double gravity, PhysicsObject *ph) {
    if (ph->getNextPos(deltaTime, gravity).x <= -5.7 + ph->getCircleCollider()->getRadius()) {
        ph->setImpulse(-ph->getForce());
    } else if (ph->getNextPos(deltaTime, gravity).x >= 2.5 + ph->getCircleCollider()->getRadius()) {
        ph->setImpulse(-ph->getForce());
    } else if (ph->getNextPos(deltaTime, gravity).y <= -3.05 + ph->getCircleCollider()->getRadius()) {
        ph->setImpulse(-ph->getForce());
    } else if (ph->getNextPos(deltaTime, gravity).y >= 1.2 + ph->getCircleCollider()->getRadius()) {
        ph->setImpulse(-ph->getForce());
    } else return false;
    return true;
}
