#pragma once

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

#include "Renderer/VertexBuffer.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/Texture.hpp"
#include "Renderer/Shader.hpp"
#include "Physics/Components/PhysicsObject.hpp"

// Forward declaration
class World;

class GameObject {
public:
    explicit GameObject(World* world) : m_physicsObject(nullptr), m_world(world) {}
    virtual ~GameObject() = default;
    virtual void update(double deltaTime) = 0;
    inline bool isPhysicsObject() const {
        return m_physicsObject != nullptr;
    }
    virtual void draw() = 0;
    World* m_world;
    PhysicsObject* m_physicsObject;
};