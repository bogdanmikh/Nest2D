#pragma once

#include "SimulationLevel.hpp"

#include "Game/Scripts/Molecule.hpp"
#include "Game/Scripts/Border.hpp"

SimulationLevel::~SimulationLevel() {
    delete shader;
}

void SimulationLevel::start(World* world, Camera* camera) {
    shader = new Shader("../resources/shaders/vst.glsl", "../resources/shaders/fst.glsl");
    camera->setShader(shader);
    // стены
    auto border1 = new Border(world, shader, camera);
    border1->setSize(0.1f, 5.f);
    border1->setPosition(-5.6f, -3.f);
    world->addActor(border1);
    auto border2 = new Border(world, shader, camera);
    border2->setSize(0.1f, 5.f);
    border2->setPosition(3.25f, -3.f);
    world->addActor(border2);
    auto border3 = new Border(world, shader, camera);
    border3->setSize(9.5f, 0.1f);
    border3->setPosition(-6.f, -2.9f);
    world->addActor(border3);
    auto border4 = new Border(world, shader, camera);
    border4->setSize(9.5f, 0.1f);
    border4->setPosition(-6.f, 1.65f);
    world->addActor(border4);

    auto molecule1 = new Molecule(world, shader, camera);
    molecule1->setSize(0.5f, 0.5f);
    molecule1->setPosition(0.f, 0.f);
    molecule1->setPhysicsObject(
            world->getPhysics()->createObjectCircle
                    (10, {molecule1->getMinX(), molecule1->getMinY()}, 0.25)
    );
    molecule1->getPhysicsObject()->setForce({-0.5, -0.8});
    world->addActor(molecule1);

    auto molecule2 = new Molecule(world, shader, camera);
    molecule2->setSize(0.5f, 0.5f);
    molecule2->setPosition(-2.f, 0.f);
    molecule2->setPhysicsObject(
            world->getPhysics()->createObjectCircle
                    (10, {molecule2->getMinX(), molecule2->getMinY()}, 0.25)
    );
    molecule2->getPhysicsObject()->setForce({0.5, -0.8});
    world->addActor(molecule2);
}
