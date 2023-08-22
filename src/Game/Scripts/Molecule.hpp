//
// Created by bogdan on 05.08.2023.
//

#pragma once

#include "Game/Core/Camera.hpp"
#include "Game/Core/Sprite.hpp"
#include "Physics/Components/PhysicsObject.hpp"

class Molecule final: public Sprite {
public:
    Molecule(World* world, Shader* shader, Camera* camera);
    void update(double deltaTime) override;
    ~Molecule() = default;
private:
    Camera *camera;
};
