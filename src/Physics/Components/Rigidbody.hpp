//
// Created by bogdan on 10.08.2023.
//
#pragma once

#include <glm/glm.hpp>

// Forward declaration
class Physics;

class Rigidbody final {
public:
    explicit Rigidbody(double mass)
            : m_mass(mass)
              , m_position(0,0)
              , m_force(0, 0)
              , m_size(1, 1) {};

    // масса
    inline double getMass() const {
        return m_mass;
    }
    inline void setMass(double mass) {
        m_mass = mass;
    }
    // сила
    inline glm::vec2 getForce() const {
        return m_force;
    }
    inline void setForce(const glm::vec2& force) {
        m_force = force;
    }
    // размер коллайдера
    inline glm::vec2 getSize() const {
        return m_size;
    }
    inline void setSize(const glm::vec2& size) {
        m_size = size;
    }
    // позиция
    inline glm::vec2 getPosition() const {
        return m_position;
    }
    // получить вершины
    std::vector<glm::vec2> getVertex() const {
        std::vector<glm::vec2> vertex;
        vertex.reserve(4);
        vertex.emplace_back(m_position.x, m_position.y);
        vertex.emplace_back(m_position.x + m_size.x, m_position.y);
        vertex.emplace_back(m_position.x, m_position.y + m_size.y);
        vertex.emplace_back(m_position.x + m_size.x, m_position.y + m_size.y);
        return vertex;
    }
    std::vector<glm::vec2> getVertex(const glm::vec2& position) const {
        std::vector<glm::vec2> vertex;
        vertex.reserve(4);
        vertex.emplace_back(position.x, position.y);
        vertex.emplace_back(position.x + m_size.x, position.y);
        vertex.emplace_back(position.x, position.y + m_size.y);
        vertex.emplace_back(position.x + m_size.x, position.y + m_size.y);
        return vertex;
    }
private:
    bool isStatic;
    double m_mass;
    glm::vec2 m_position;
    glm::vec2 m_force;
    glm::vec2 m_size;

    friend class Physics;
};
