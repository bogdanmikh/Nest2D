#include "Sprite.hpp"
#include "Renderer/Renderer.hpp"
#include "Renderer/VertexBufferLayout.hpp"

#include <glm/ext.hpp>

Sprite::Sprite(World* world, std::string texturePath, Shader* shader)
    : GameObject(world)
    , m_texture(texturePath)
    , m_position(0.f)
    , m_shader(shader)
    , m_size(1.f, 1.f) {
    //
    //      2________1
    //      |        |
    //      |        |
    //      |________|
    //      3        4
    //
    // 1 - круг, 2 - треугольник, 3 - квадрат
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

    m_vertexBuffer = new VertexBuffer(data, sizeof(float) * 24);
    delete[] data;

    VertexBufferLayout layout;
    layout.pushVec2F(1);
    layout.pushVec2F(1);

    m_vertexArray = new VertexArray();
    m_vertexArray->addBuffer(*m_vertexBuffer, layout);
}

Sprite::~Sprite() {
    delete m_vertexArray;
    delete m_vertexBuffer;
}

void Sprite::draw() {
    m_texture.bind();
    m_vertexArray->bind();
    updateModelMatrix();
    Renderer::drawArrays(6);
}

void Sprite::setPosition(float x, float y) {
    m_position.x = x;
    m_position.y = y;
}

void Sprite::setPosition(glm::vec2 position) {
    m_position = position;
}

void Sprite::translate(float x, float y) {
    m_position.x += x;
    m_position.y += y;
}

void Sprite::setSize(float width, float height) {
    m_size.x = width;
    m_size.y = height;
}

void Sprite::updateModelMatrix() {
    m_shader->use();
    glm::mat4 model = glm::translate(glm::mat4(1.f), glm::vec3(m_position, 0.f));
    model = glm::scale(model, glm::vec3(m_size, 1.f));
    m_shader->setMat4("model", model);
}

float Sprite::getMaxY() {
    return m_position.y + m_size.y;
}

float Sprite::getMinY() {
    return m_position.y;
}

float Sprite::getMaxX() {
    return m_position.x + m_size.x;
}

float Sprite::getMinX() {
    return m_position.x;
}

double Sprite::distanceTo(Sprite* other) {
    return sqrt((getMinX() - other->getMinX()) * (getMinX() - other->getMinX()) + (getMinY() - other->getMinY()) * (getMinY() - other->getMinY()));
}
