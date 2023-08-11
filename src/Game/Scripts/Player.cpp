//
// Created by bogdan on 05.08.2023.
//

#include "Player.hpp"
#include "Game/LevelManager/LevelManager.hpp"
#include "Game/Core/Camera.hpp"

Player::Player(World* world, Shader* shader, Camera* camera)
        : Sprite(world, "../resources/textures/ball.png", shader)
          , camera(camera) {
    setPosition(0.f, 0.f);
    setSize(1., 1.);
}

void Player::update(double deltaTime) {
    camera->setPosition(0., 0., 5.);
    draw();
}
