#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"

class Menu: public GameObject {
public:
    void update(double deltaTime) override;
};