#include "MenuLevel.hpp"

#include "Game/Scripts/Menu.hpp"

MenuLevel::~MenuLevel() {
    delete shader;
}

void MenuLevel::start(World* world, Camera* camera) {
    Menu *menu = new Menu(world);
    world->addActor(menu);
}