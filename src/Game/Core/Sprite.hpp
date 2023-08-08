#pragma once

#include <iostream>
#include <glm/glm.hpp>

#include "Renderer/VertexBuffer.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/Texture.hpp"
#include "Renderer/Shader.hpp"

class Sprite {
public:
    Sprite(std::string texturePath, Shader* shader);
    ~Sprite();
    void setPosition(float x, float y, float z);
    void translate(float x, float y, float z);
    void setSize(float width, float height);

    float getMaxY();
    float getMinY();
    float getMaxX();
    float getMinX();

    double distanceTo(Sprite* other);

    void draw();
    bool isCollision;
private:
    void updateModelMatrix();

    Texture texture;
    VertexBuffer* vertexBuffer;
    VertexArray* vertexArray;
    glm::vec3 position;
    glm::vec2 size;
protected:
    Shader* shader;
};