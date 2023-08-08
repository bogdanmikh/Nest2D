//
// Created by bogdan on 05.08.2023.
//

#include "Player.hpp"
#include "Application/Application.hpp"
#include "Game/LevelManager/LevelManager.hpp"
#include "Game/Core/GovnoCollisionDetector.hpp"
#include "Game/Core/Camera.hpp"
#include "Game/LevelManager/LevelManager.hpp"

#include <imgui.h>

Player::Player(Shader* shader, Camera* camera)
        : Sprite("../resources/textures/ball.png", shader)
          , camera(camera) {
    physics = new Physics(0);
    physics->setForce({5, 0});
    setPosition(0.f, 0.f, 0.f);
    setSize(1., 1.);
}

void Player::update(double deltaTime) {
    camera->setPosition(0., 0., 5.);
    /*auto& colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4{ 0.f, 0.f, 0.f, 0.f };
    //задать позицию у окна
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
    ImGui::Begin("Player info", nullptr, ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoResize);
    ImGui::Text("Player, x: %f, y: %f", getMinX(), getMinY());
    //сдвинуть кнопку перед созданием её
    ImGui::SetCursorPos(ImVec2(10, 50));
    if(ImGui::Button("RESTART LEVEL", ImVec2(200, 50))) {
        ImGui::End();
        Application::getInstance()->loadLevel(createCurrentLevel());
        return;
    }
    ImGui::Text("Money: %d of %d", 1, 2);
    if(ImGui::Button("MENU", ImVec2(200, 50))) {
        ImGui::End();
        Application::getInstance()->loadLevel(createMenuLevel());
        return;
    }
    ImGui::End();
    */
    physics->updateForce({0.05, 0.001});
    translate(physics->getForce(deltaTime).x,
              physics->getForce(deltaTime).y - physics->getGravity(deltaTime), 0);
    draw();
}

Player::~Player() {
    delete physics;
}