#include "LevelManager.hpp"

#include "Game/Levels/MenuLevel.hpp"
#include "Game/Levels/SimulationLevel.hpp"

int currentLevelIndex = 0;
// Когда добавишь еще уровни, прибавляй
const int numberOfLevels = 2;

Level* createCurrentLevel() {
    return createLevelWithIndex(currentLevelIndex);
}

Level* createMenuLevel() {
    return new MenuLevel();
}

Level* createLevelWithIndex(int index) {
    currentLevelIndex = index;
    if (index == -1) {
        return new MenuLevel();
    } else if (index == 0) {
        return new SimulationLevel();
    } else {
        // не должно происходить
        assert(false);
    }
}

void increaseLevelNumber() {
    currentLevelIndex++;
    if (currentLevelIndex == numberOfLevels) {
        currentLevelIndex = -1;
    }
}