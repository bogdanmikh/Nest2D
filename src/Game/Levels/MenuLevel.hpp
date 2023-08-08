#pragma once

#include "Game/Level.hpp"

#include "Game/Core/Camera.hpp"
#include "Renderer/Shader.hpp"

class MenuLevel : public Level {
public:
    ~MenuLevel();
    void start(World* world, Camera* camera) override;
private:
    Shader* shader;
};