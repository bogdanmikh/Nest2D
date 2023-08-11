//
// Created by bogdan on 05.08.2023.
//

#pragma once

#include "Game/Core/Camera.hpp"
#include "Game/Core/Sprite.hpp"
#include "Physics/Components/Rigidbody.hpp"

class Player final: public Sprite {
public:
    Player(World* world, Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    ~Player() = default;
private:
    Camera *camera;
};
