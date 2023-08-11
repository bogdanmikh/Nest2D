#pragma once

#include "Game/Core/GameObject.hpp"
#include "Game/Direction.hpp"

class GovnoCollisionDetector {
public:
    static bool moveAcceptable(GameObject* entity, Direction direction, float amount);
};