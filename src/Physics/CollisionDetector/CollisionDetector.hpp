//
// Created by bogdan on 19.08.2023.
//
#pragma once

#include "Physics/Components/PhysicsObject.hpp"

class CollisionDetector {
public:
    static bool
    canMoveCC(double deltaTime, double gravity, const PhysicsObject *ph1, const PhysicsObject *ph2);

    static bool
    canMoveBB(double deltaTime, double gravity, const PhysicsObject *ph1, const PhysicsObject *ph2);

    static bool
    canMoveBC(double deltaTime, double gravity, const PhysicsObject *ph1, const PhysicsObject *ph2);

    static void resolveCollisionCC(double deltaTime, double gravity,
                                   PhysicsObject *ph1, PhysicsObject *ph2);

    static void resolveCollisionBB(double deltaTime, double gravity, PhysicsObject *ph1,
                                   PhysicsObject *ph2);

    static void resolveCollisionBC(double deltaTime, double gravity, PhysicsObject *ph1,
                                   PhysicsObject *ph2);

    static bool resolveCollisionCW(double deltaTime, double gravity, PhysicsObject *ph1);

    static glm::vec2 resolveCollisionBW(double deltaTime, double gravity, PhysicsObject *ph1);
};
