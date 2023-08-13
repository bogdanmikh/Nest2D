//
// Created by bogdan on 09.08.2023.
//

#include "CollisionDetector.hpp"

#include <cmath>

glm::vec2 CollisionDetector::support(const std::vector<glm::vec2>& polygon, const glm::vec2& direction) {
    double maxDotProduct = polygon[0].x * direction.x + polygon[0].y * direction.y;
    glm::vec2 farthestPoint = polygon[0];

    for (int i = 1; i < polygon.size(); i++) {
        double dotProduct = polygon[i].x * direction.x + polygon[i].y * direction.y;
        if (dotProduct > maxDotProduct) {
            maxDotProduct = dotProduct;
            farthestPoint = polygon[i];
        }
    }

    return farthestPoint;
}

bool CollisionDetector::gjk(const std::vector<glm::vec2>& polygonA, const std::vector<glm::vec2>& polygonB) {
    std::vector<glm::vec2> simplex;
    glm::vec2 direction = { 1.0, 0.0 };

    glm::vec2 initialPoint = support(polygonA, direction) - support(polygonB, -direction);
    simplex.push_back(initialPoint);

    direction = {-initialPoint.x, -initialPoint.y};

    for (int i = 0; i <= 16; i++) {
        glm::vec2 supportA = support(polygonA, direction);
        glm::vec2 supportB = support(polygonB, -direction);
        glm::vec2 newPoint = supportA - supportB;

        if ((newPoint.x * direction.x + newPoint.y * direction.y) < 0) {
            return false;
        }

        simplex.push_back(newPoint);

        if (simplex.size() == 3) {
            glm::vec2 AB = simplex[1] - simplex[0];
            glm::vec2 AO = -simplex[0];
            glm::vec2 ABC = glm::vec2(-AB.y, AB.x);
            glm::vec2 AOC = glm::vec2(-AO.y, AO.x);

            if (ABC.x * AOC.x + ABC.y * AOC.y > 0) {
                direction = ABC;
            } else {
                direction = -ABC;
                simplex.erase(simplex.begin());
            }
        } else if (simplex.size() == 4) {
            glm::vec2 AB = simplex[2] - simplex[0];
            glm::vec2 AC = simplex[1] - simplex[0];
            glm::vec2 AO = -simplex[0];

            glm::vec2 ABC = glm::vec2(-AB.y, AB.x);
            glm::vec2 ACB = glm::vec2(-AC.y, AC.x);

            if (ABC.x * AO.x + ABC.y * AO.y > 0) {
                if (ACB.x * AO.x + ACB.y * AO.y > 0) {
                    return true;
                } else {
                    simplex.erase(simplex.begin() + 1);
                    direction = ACB;
                }
            } else {
                direction = ABC;
                simplex.erase(simplex.begin() + 2);
            }
        }
    }
}

