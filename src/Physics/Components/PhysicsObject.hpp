//
// Created by bogdan on 10.08.2023.
//
#pragma once

#include <glm/glm.hpp>

// Forward declaration
class Physics;

class PhysicsObject final {
private:
    class Box2D final {
    public:
        Box2D(const glm::vec2& size, const glm::vec2& offset)
                : m_size(size)
                  , m_offset(offset) {}

        Box2D(const glm::vec2& size)
                : Box2D(size, {0, 0}) {}

        inline glm::vec2 getSize() const {
            return m_size;
        }

        inline void setSize(const glm::vec2& size) {
            m_size = size;
        }

        inline glm::vec2 getOffset() const {
            return m_offset;
        }

        inline void setOffset(const glm::vec2 &offset) {
            m_offset = offset;
        }
    private:
        // размер коллайдера
        glm::vec2 m_size;
        // смещение относительно привязанного обьекта
        glm::vec2 m_offset;
    };
    class Circle2D final {
    public:
        Circle2D(const double radius, const glm::vec2& offset)
                : m_radius(radius)
                  , m_offset(offset) {}

        Circle2D(const double radius)
                : Circle2D(radius, {0, 0}) {}


        double getRadius() const {
            return m_radius;
        }

        inline void setRadius(const double radius) {
            m_radius = radius;
        }

        inline glm::vec2 getOffset() const {
            return m_offset;
        }

        inline void setOffset(const glm::vec2 &offset) {
            m_offset = offset;
        }
    private:
        // размер коллайдера
        double m_radius;
        // смещение относительно привязанного обьекта
        glm::vec2 m_offset;
    };

    bool m_isTrigger;
    bool m_canMove;
    double m_mass;
    Box2D *m_box2D;
    Circle2D *m_circle2D;
    glm::vec2 m_impulse;
    glm::vec2 m_position;
    glm::vec2 m_force;

public:
    explicit PhysicsObject(double mass)
          : m_mass(mass)
          , m_canMove(true)
          , m_isTrigger(false)
          , m_position(0,0)
          , m_impulse(0, 0)
          , m_force(0, 0) {};

    explicit PhysicsObject(double mass, bool isTrigger)
          : m_mass(mass)
          , m_canMove(true)
          , m_isTrigger(isTrigger)
          , m_position(0,0)
          , m_impulse(0, 0)
          , m_force(0, 0) {};

    ~PhysicsObject() {
        if (m_box2D != nullptr) {
            delete m_box2D;
        }
        if (m_circle2D != nullptr) {
            delete m_circle2D;
        }
    }

    inline bool isTrigger() const {
        return m_isTrigger;
    }

    inline void setIsTrigger(bool isTrigger) {
        m_isTrigger = isTrigger;
    }

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

    // позиция
    inline glm::vec2 getPosition() const {
        return m_position;
    }

    inline void setPosition(const glm::vec2& position) {
        m_position = position;
    }

    inline Box2D* createBox(const glm::vec2& size, const glm::vec2& offset) {
        m_box2D = new PhysicsObject::Box2D(size, offset);
        return m_box2D;
    }

    inline Box2D* createBox(const glm::vec2& size) {
        return createBox(size, {0, 0});
    }

    inline Box2D* getBoxCollider() const {
        if (m_box2D == nullptr) return {};
        return m_box2D;
    }

    inline Circle2D* createCircle(const double radius, const glm::vec2& offset) {
        m_circle2D = new PhysicsObject::Circle2D(radius, offset);
        return m_circle2D;
    }

    inline Circle2D* createCircle(const double radius) {
        return createCircle(radius, {0, 0});
    }

    inline Circle2D* getCircleCollider() const {
        if (m_circle2D == nullptr) return {};
        return m_circle2D;
    }

    inline void setImpulse(const glm::vec2& impulse) {
        m_impulse = impulse;
    }

    glm::vec2 getNextPos(double deltaTime, double gravity) const {
        glm::vec2 nextPos = {
                (getForce().x * deltaTime + m_position.x),
                ((getForce().y + -gravity) * deltaTime + m_position.y)
        };
        return nextPos;
    }

    glm::vec2 getNextImpulsePos(double deltaTime, double gravity) const {
        glm::vec2 nextPos = {
                m_position.x + (m_impulse.x / getMass() * deltaTime),
                (m_position.y + (m_impulse.y) / getMass() * deltaTime)
        };
        return nextPos;
    }

    friend class Physics;
};
