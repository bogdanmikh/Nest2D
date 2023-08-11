//
// Created by bogdan on 09.08.2023.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>

class CollisionDetector {

    struct Polygon {
        std::vector<glm::vec2> vertices;
    };

    struct Circle {
        glm::vec2 center;
        float radius;
    };

    struct Simplex {
        glm::vec2 a, b, c, d;
        int count;
    };

    float DotProduct(const glm::vec2 &a, const glm::vec2 &b) {
        return a.x * b.x + a.y * b.y;
    }

    float Length(const glm::vec2 &v) {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

    glm::vec2 Normalize(const glm::vec2 &v) {
        float length = Length(v);
        return {v.x / length, v.y / length};
    }

    glm::vec2 Support(const Polygon &polygon, const glm::vec2 &direction) {
        // Функция Support для многоугольника
        float maxDotProduct = -std::numeric_limits<float>::infinity();
        glm::vec2 supportPoint;

        // Находим вершину многоугольника, с максимальным скалярным произведением с направлением
        for (const glm::vec2 &vertex: polygon.vertices) {
            float dotProduct = vertex.x * direction.x + vertex.y * direction.y;
            if (dotProduct > maxDotProduct) {
                maxDotProduct = dotProduct;
                supportPoint = vertex;
            }
        }

        return supportPoint;
    }

    glm::vec2 Support(const Circle &circle, const glm::vec2 &direction) {
        // Функция Support для круга
        glm::vec2 supportPoint;
        float length = Length(direction);

        if (length > 0.0f) {
            float scale = circle.radius / length;
            supportPoint.x = circle.center.x + scale * direction.x;
            supportPoint.y = circle.center.y + scale * direction.y;
        } else {
            supportPoint = circle.center;
        }

        return supportPoint;
    }

    bool GJKCollisionDetection(const Polygon &shapeA, const Polygon &shapeB) {
        // Инициализация Simplex и выбор начального направления
        glm::vec2 direction = {1.0f, 0.0f};
        Simplex simplex;
        simplex.count = 0;

        while (true) {
            simplex.a = Support(shapeA, direction);
            simplex.b = Support(shapeB, direction);

            glm::vec2 ao = {-simplex.a.x, -simplex.a.y};
            if (simplex.b.x * ao.x + simplex.b.y * ao.y < 0.0f) {
                return false;
            }

            if (simplex.count >= 2) {
                glm::vec2 ab = {simplex.b.x - simplex.a.x, simplex.b.y - simplex.a.y};
                glm::vec2 ac = {simplex.c.x - simplex.a.x, simplex.c.y - simplex.a.y};
                glm::vec2 abc = {ab.y,
                                   -ab.x}; // Нормаль к ребру ab для проверки в плоскости треугольника

                // Проверяем, что точка d находится внутри треугольника abc
                if (DotProduct(ac, abc) * DotProduct(simplex.d, abc) <= 0.0f) {
                    return true;
                }

                // Проверяем, что точка d находится внутри треугольника acd
                glm::vec2 acd = {ac.y,
                                   -ac.x}; // Нормаль к ребру ac для проверки в плоскости треугольника
                if (DotProduct(ab, acd) * DotProduct(simplex.d, acd) <= 0.0f) {
                    simplex.c = simplex.d;
                    direction = acd;
                } else {
                    glm::vec2 adb = {-ab.y,
                                       ab.x}; // Нормаль к ребру ad для проверки в плоскости треугольника
                    if (DotProduct(ab, adb) * DotProduct(simplex.d, adb) <= 0.0f) {
                        simplex.b = simplex.d;
                        direction = adb;
                    } else {
                        return true;
                    }
                }
            } else if (simplex.count == 1) {
                glm::vec2 ab = {simplex.b.x - simplex.a.x, simplex.b.y - simplex.a.y};
                direction = Normalize({-ab.y, ab.x});
                simplex.count = 2;
            } else {
                return true;
            }
        }
    }

    bool GJKCollisionDetection(const Polygon &polygon, const Circle &circle) {
        // Инициализация Simplex и выбор начального направления
        glm::vec2 direction = {1.0f, 0.0f};
        Simplex simplex;
        simplex.count = 0;
    };
};