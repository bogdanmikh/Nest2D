//
// Created by bogdan on 09.08.2023.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <glm/glm.hpp>

class CollisionDetector {
private:
    glm::vec2 support(const std::vector<glm::vec2>& polygon, const glm::vec2& direction);
public:
    bool gjk(const std::vector<glm::vec2>& polygonA, const std::vector<glm::vec2>& polygonB);
};
