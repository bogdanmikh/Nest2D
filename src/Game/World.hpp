#pragma once

#include "Game/Core/GameObject.hpp"
#include "Physics/Physics.hpp"

#include <vector>

class World {
public:
    inline World() : m_physics() {}
    void update(double deltaTime);
    void addActor(GameObject* actor);
    PhysicsObject* createPhysicsObjectBox(double mass, glm::vec2& pos, glm::vec2& size) {
        return m_physics.createObjectBox(mass, pos, size);
    }
    PhysicsObject* createPhysicsObjectCircle(double mass, glm::vec2& pos, double radius) {
        return m_physics.createObjectCircle(mass, pos, radius);
    }
    void deleteActor(GameObject* actor);
    void deleteAll();
    inline Physics* getPhysics() {
        return &m_physics;
    }
private:
    std::vector<GameObject*> gameObjects;
    Physics m_physics;
};