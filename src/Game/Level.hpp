#pragma once

#include "World.hpp"
#include "Physics/Physics.hpp"
#include "Game/Core/Camera.hpp"

class Level {
public:   
    virtual ~Level() = default;
    virtual void start(World* world, Camera* camera) = 0;
};