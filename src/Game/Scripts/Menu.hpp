#pragma once

#include "Game/Core/GameObject.hpp"

class Menu: public GameObject {
public:
    explicit Menu(World* world): GameObject(world) {}
    ~Menu() override = default;

    void update(double deltaTime) override;
    void draw() override {}
};