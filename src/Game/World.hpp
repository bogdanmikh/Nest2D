#pragma once

#include "Game/Core/GameObject.hpp"
#include "Physics/Physics.hpp"

#include <vector>

class World {
public:
    inline World() : m_physics() {}
    void update(double deltaTime);
    void addActor(GameObject* actor);
    Rigidbody* createRigidbody(double mass, glm::vec2 pos) {
        return m_physics.createObject(mass, pos);
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