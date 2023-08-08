//
// Created by bogdan on 05.08.2023.
//

#pragma once

#include "Game/GameObject/GameObject.hpp"
#include "Game/Core/Sprite.hpp"
#include "Game/Core/Camera.hpp"
#include "Physics/Physics.hpp"

class Player: public GameObject, public Sprite {
public:
    Player(Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    ~Player();
private:
    Physics *physics;
    Camera *camera;
};
