#include "World.hpp"

void World::update(double deltaTime) {
    for(int i = 0; i < gameObjects.size(); i++) {
        gameObjects[i]->update(deltaTime);
    }
}

void World::addActor(GameObject* actor) {
    gameObjects.insert(gameObjects.begin(), actor);
}

void World::deleteActor(GameObject* actor) {
    auto it = std::find(gameObjects.begin(), gameObjects.end(), actor);
    if(it != gameObjects.end()) {
        gameObjects.erase(it);
        delete actor;
    }
}

void World::deleteAll() {
    for(auto& actor: gameObjects) {
        delete actor;
    }
    gameObjects.clear();
}

std::vector<GameObject*>& World::getAllActors() {
    return gameObjects;
}

std::vector<Sprite*> World::getAllCollisions() {
    std::vector<Sprite*> result;
 
    for (int i = 0; i < gameObjects.size(); i++) {
        auto sprite = dynamic_cast<Sprite*>(gameObjects[i]);
        if (sprite && sprite->isCollision) {
            result.push_back(sprite);
        }
    }
 
    return result;
}
