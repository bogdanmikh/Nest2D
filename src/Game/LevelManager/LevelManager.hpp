#pragma once

#include "Game/Level.hpp"

Level* createCurrentLevel();

Level* createMenuLevel();

Level* createLevelWithIndex(int index);

/// Прибавляет номер уровня на 1. 
/// Если текущий уровень последний - номер становится 0
void increaseLevelNumber();