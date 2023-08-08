#pragma once

#include "Game/Level.hpp"

#include "Game/Core/Camera.hpp"
#include "Renderer/Shader.hpp"

class SimulationLevel : public Level {
public:
    ~SimulationLevel();
    void start(World* world, Camera* camera) override;
private:
    Shader* shader;
};