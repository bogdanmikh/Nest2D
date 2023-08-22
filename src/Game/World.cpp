#include "World.hpp"
#include "Game/Core/Sprite.hpp"

void World::update(double deltaTime) {
    // Обновление физики
    m_physics.update(deltaTime);
    // Применение изменений в физике к объектам
    for(auto gameObject : gameObjects) {
        if (!gameObject->isPhysicsObject()) {
            continue;
        }
        auto sprite = dynamic_cast<Sprite*>(gameObject);
        if(!sprite) {
            continue;
        }
        auto ph = sprite->m_physicsObject;
        sprite->setPosition(ph->getPosition());
    }
    for (auto & gameObject : gameObjects) {
        gameObject->update(deltaTime);
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
