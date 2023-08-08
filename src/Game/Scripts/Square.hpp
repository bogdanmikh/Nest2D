#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Core/Camera.hpp"

class Square: public GameObject, public Sprite {
public:
    Square(Shader* shader);
    void update(double deltaTime) override;
};