//
// Created by bogdan on 21.08.2023.
//

#pragma once

#include "Game/Core/Camera.hpp"
#include "Game/Core/Sprite.hpp"
#include "Physics/Components/PhysicsObject.hpp"

class Border final: public Sprite {
public:
    Border(World* world, Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    ~Border() = default;
private:
    Camera *camera;
};