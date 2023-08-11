#include "Application.hpp"

#include "Renderer/Renderer.hpp"
#include "Renderer/ImGui.hpp"
#include "Game/LevelManager/LevelManager.hpp"

#include <chrono>
#include <iostream>
#include <glm/glm.hpp>

uint64_t getMillis() {
    auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    return now.count();
}

Application* Application::s_instance;

Application* Application::getInstance() {
    return s_instance;
}

Application::Application()
    : currentLevel(nullptr), world() {
    s_instance = this;
    std::cout << "Nest2D version BETA\n";

    window = new Window("OpenGl", 640, 480);
    Renderer::init();

    Renderer::setClearColor(.235f, .235f, .235f, 1.0f);
    timeMillis = getMillis();

    camera = new Camera;
    camera->setFieldOfView(glm::radians(60.f));
    camera->setRotation(0.f, 0.f, 0.f);

    ImGui_Init(window->getNativeHandle());

    loadLevel(createMenuLevel());
}

Application::~Application() {
    ImGui_Shutdown();
    s_instance = nullptr;
    world.deleteAll();
    delete currentLevel;
    delete camera;
    delete window;
}

void Application::loop() {
    while (!window->shouldClose()) {
        uint64_t lastTime = timeMillis;
        timeMillis = getMillis();
        deltaTimeMillis += timeMillis - lastTime;
        if (deltaTimeMillis < (1000 / maximumFps)) {
            continue;
        }
        oneSecondTimeCount += deltaTimeMillis;

        thisSecondFramesCount++;
        if (oneSecondTimeCount >= 1000) {
            fps = thisSecondFramesCount;
            std::cout << "FPS: " << fps << std::endl;
            thisSecondFramesCount = 0;
            oneSecondTimeCount = 0;
        }

        double deltaTime = deltaTimeMillis / 1000.0;
        deltaTimeMillis = 0;
        Renderer::clear();

        ImGui_NewFrame();
        world.update(deltaTime);
        ImGui_EndFrame();

        if(window->isKeyPressed(Key::ESCAPE)) {
            close();
        }

        glm::vec2 resolution = window->getSize();
        camera->updateAspectRatio(resolution.x / resolution.y);
        Renderer::setRenderBufferSize(resolution.x, resolution.y);

        window->swapBuffers();
        window->pollEvents();
    }
}

void Application::loadLevel(Level* level) {
    world.deleteAll();
    if (currentLevel != nullptr) {
        delete currentLevel;
    }
    currentLevel = level;
    level->start(&world, camera);
}

void Application::close() {
    window->setShouldClose();
}
