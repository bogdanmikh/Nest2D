#pragma once

#include "Game/Core/Sprite.hpp"
#include "Game/Direction.hpp"

class GovnoCollisionDetector {
public:
    static bool moveAcceptable(Sprite* entity, Direction direction, float amount);
};