#include "SimulationLevel.hpp"

#include "Game/Scripts/Player.hpp"

SimulationLevel::~SimulationLevel() {
    delete shader;
}

void SimulationLevel::start(World* world, Camera* camera) {
    shader = new Shader("../resources/shaders/vst.glsl", "../resources/shaders/fst.glsl");
    camera->setShader(shader);

    auto player = new Player(world, shader, camera);
    player->setSize(1.f, 1.f);
    player->setPosition(-5.f, 0.f);
    player->setRigidbody(
            world->getPhysics()->createObject(10, {player->getMinX(), player->getMinY()})
    );
    world->addActor(player);

//    auto square = new Square(shader);
//    square->setSize(5.f,2.f);
//    square->setPosition(-2.f, -2.f, 0.f);
//    world->addActor(square);
}
