#pragma once

#include "GameObject.hpp"

class Sprite : public GameObject {
public:
    Sprite(World* world, std::string texturePath, Shader* shader);
    ~Sprite() override;
    void setPosition(float x, float y);
    void setPosition(glm::vec2 position);
    void translate(float x, float y);
    void setSize(float width, float height);

    float getMinY();
    float getMaxY();
    float getMaxX();
    float getMinX();

    void update(double deltaTime) override {}

    double distanceTo(Sprite* other);

    inline void setPhysicsObject(PhysicsObject* physicsObject) {
        m_physicsObject = physicsObject;
    }

    inline PhysicsObject* getPhysicsObject() {
        return m_physicsObject;
    }

    void draw() override;
private:
    void updateModelMatrix();
    Texture m_texture;
    VertexBuffer* m_vertexBuffer;
    VertexArray* m_vertexArray;
    glm::vec2 m_position;
    glm::vec2 m_size;
protected:
    Shader* m_shader;
};