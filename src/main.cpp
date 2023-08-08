#include "Application/Application.hpp"

int main() {
    Application* app = new Application();
    app->loop();
    delete app;
}
