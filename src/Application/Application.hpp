#pragma once

#include "Window/Window.hpp"
#include "Game/World.hpp"
#include "Game/Scripts/Square.hpp"
#include "Game/Level.hpp"

class Application {
public:
    Application();
    ~Application();
    void loop();

    World world;
    Window* window;   
    int fps;
    static Application* getInstance();
    void close();
    void loadLevel(Level* level);

private:
    static Application *s_instance;
    Camera* camera; 
    Level* currentLevel;
    int maximumFps = 60;
    uint64_t deltaTimeMillis = 0;
    int thisSecondFramesCount = 0;
    uint64_t timeMillis; 
    uint64_t oneSecondTimeCount = 0;
};