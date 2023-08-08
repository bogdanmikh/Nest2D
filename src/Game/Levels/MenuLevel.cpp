#include "MenuLevel.hpp"

#include "Game/Scripts/Menu.hpp"

MenuLevel::~MenuLevel() {
    delete shader;
}

void MenuLevel::start(World* world, Camera* camera) {
    world->addActor(new Menu());
}