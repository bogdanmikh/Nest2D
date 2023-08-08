#include "Sprite.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/VertexBufferLayout.hpp"

#include <glm/ext.hpp>

Sprite::Sprite(std::string texturePath, Shader* shader)
    : isCollision(false)
    , texture(texturePath)
    , position(0.f)
    , shader(shader)
    , size(1.f, 1.f) {
    //
    //      2________1
    //      |        |
    //      |        |
    //      |________|
    //      3        4
    //

    // Ось объекта в точке 3
    float *data = new float[24] {
    //    x   y          u    v
        1.f, 1.f,       1.f, 0.f,   // 1
        0.f, 1.f,       0.f, 0.f,   // 2
        0.f, 0.f,       0.f, 1.f,   // 3
        1.f, 1.f,       1.f, 0.f,   // 1
        0.f, 0.f,       0.f, 1.f,   // 3
        1.f, 0.f,       1.f, 1.f,   // 4
    };

    // Ось объекта в точке 2
    // float *data = new float[24] {
    // //    x   y          u    v
    //     1.f, 0.f,       1.f, 0.f,   // 1
    //     0.f, 0.f,       0.f, 0.f,   // 2
    //     0.f, -1.f,      0.f, 1.f,   // 3
    //     1.f, 0.f,       1.f, 0.f,   // 1
    //     0.f, -1.f,      0.f, 1.f,   // 3
    //     1.f, -1.f,      1.f, 1.f,   // 4
    // };

    vertexBuffer = new VertexBuffer(data, sizeof(float) * 24);
    delete[] data;

    VertexBufferLayout layout;
    layout.pushVec2F(1);
    layout.pushVec2F(1);

    vertexArray = new VertexArray();
    vertexArray->addBuffer(*vertexBuffer, layout);
}

Sprite::~Sprite() {
    delete vertexArray;
    delete vertexBuffer;
}

void Sprite::draw() {
    texture.bind();
    vertexArray->bind();
    updateModelMatrix();
    Renderer::drawArrays(6);
}

void Sprite::setPosition(float x, float y, float z) {
    position.x = x;
    position.y = y;
    position.z = z;
}

void Sprite::translate(float x, float y, float z) {
    position.x += x;
    position.y += y;
    position.z += z;
}

void Sprite::setSize(float width, float height) {
    size.x = width;
    size.y = height;
}

void Sprite::updateModelMatrix() {
    shader->use();
    glm::mat4 model = glm::translate(glm::mat4(1.f), position);
    model = glm::scale(model, glm::vec3(size, 1.f));
    shader->setMat4("model", model);
}

float Sprite::getMaxY() {
    return position.y + size.y;
}

float Sprite::getMinY() {
    return position.y;
}

float Sprite::getMaxX() {
    return position.x + size.x;
}

float Sprite::getMinX() {
    return position.x;
}

double Sprite::distanceTo(Sprite* other) {
    return sqrt((getMinX() - other->getMinX()) * (getMinX() - other->getMinX()) + (getMinY() - other->getMinY()) * (getMinY() - other->getMinY()));
}
