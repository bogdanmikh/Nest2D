#include "CollisionDetector.hpp"
#include "Application/Application.hpp"

bool CollisionDetector::moveAcceptable(
    Sprite* entity, 
    Direction direction, 
    float amount
) {
    auto collisionList = Application::getInstance()->world.getAllCollisions();
    for (auto& collision: collisionList) {
        if (collision == entity) { continue; }
        // низ объекта + сдвиг вниз меньше верха препятствия
        if (direction == Direction::DOWN
                && (entity->getMinY() + amount < collision->getMaxY()
                && entity->getMaxY() > collision->getMinY()
            )
                && (entity->getMaxX() > collision->getMinX()
                && entity->getMinX() < collision->getMaxX()
            )
        ) {
            return false;
        }
        // верх объекта + сдвиг вверх больше низа препятствия
        if (direction == Direction::UP
                && (entity->getMinY() < collision->getMaxY()
                && entity->getMaxY() + amount > collision->getMinY()
            )
                && (entity->getMaxX() > collision->getMinX()
                && entity->getMinX() < collision->getMaxX()
            )
        ) {
            return false;
        }
        // левая сторона объекта + сдвиг влево меньше правой стороны препятствия
        if (direction == Direction::LEFT
                && (entity->getMaxX() > collision->getMinX()
                && entity->getMinX() + amount < collision->getMaxX()
            )
                && (entity->getMinY() < collision->getMaxY()
                && entity->getMaxY() > collision->getMinY()
            )
        ) {
            return false;
        }
        // правая сторона объекта + сдвиг вправо больше левой стороны препятствия
        if (direction == Direction::RIGHT
                && (entity->getMaxX() + amount > collision->getMinX()
                && entity->getMinX() < collision->getMaxX()
            )
                && (entity->getMinY() < collision->getMaxY()
                && entity->getMaxY() > collision->getMinY()
            )
        ) {
            return false;
        }
    }

    return true;
}