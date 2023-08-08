#include "Square.hpp"
#include "Application/Application.hpp"
#include "Game/LevelManager/LevelManager.hpp"
#include "Game/Core/CollisionDetector.hpp"
#include "Game/Core/Camera.hpp"
#include "Game/LevelManager/LevelManager.hpp"

#include <imgui.h>

Square::Square(Shader* shader)
    : Sprite("../resources/textures/Earth.png", shader) {
    isCollision = true;
    setPosition(0.f, 0.f, 0.f);
    setSize(1., 1.);
}

void Square::update(double deltaTime) {
    draw();
}