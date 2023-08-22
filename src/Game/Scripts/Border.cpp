//
// Created by bogdan on 21.08.2023.
//

#include "Border.hpp"

Border::Border(World* world, Shader* shader, Camera* camera)
        : Sprite(world, "../resources/textures/wall.png",  shader)
          , camera(camera) {
    setPosition(0.f, 0.f);
    setSize(1., 1.);
}

void Border::update(double deltaTime) {
    camera->setPosition(0., 0., 5.);
    draw();
}