//
// Created by bogdan on 05.08.2023.
//

#pragma once
#include <chrono>
#include <random>

#include "Molecule.hpp"
#include "Game/LevelManager/LevelManager.hpp"
#include "Game/Core/Camera.hpp"

std::string getRandomTexture() {
    std::vector<std::string> tex = {
            "../resources/textures/1.png", "../resources/textures/2.png",
            "../resources/textures/3.png", "../resources/textures/4.png",
            "../resources/textures/5.png", "../resources/textures/6.png",
            "../resources/textures/6.png", "../resources/textures/8.png",
            "../resources/textures/8.png", "../resources/textures/10.png",
            "../resources/textures/11.png"};
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::mt19937 rng(seed);

    // Генерируем случайное число
    int randomNumber = rng() % 11;
    return tex[randomNumber];
}

Molecule::Molecule(World* world, Shader* shader, Camera* camera)
        : Sprite(world, getRandomTexture(),  shader)
          , camera(camera) {
    setPosition(0.f, 0.f);
    setSize(1., 1.);
}

void Molecule::update(double deltaTime) {
    camera->setPosition(0., 0., 5.);
    draw();
}
