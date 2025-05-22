#include "engine.hpp"

GameEngine::GameEngine(const std::string& name, float width, float height)
    : width(width), height(height) {
    InitWindow(width, height, name.c_str());
    SetTargetFPS(15);
    rock.init("assets/rock.png", {0, 0, 1086, 1086}, {0, 400, 400, 400});
    paper.init("assets/paper.png", {0, 0, 1086, 1086}, {0, 400, 400, 400});
    scissors.init("assets/scissors.png", {0, 0, 1086, 1086},
                  {0, 400, 400, 400});
}

GameEngine::~GameEngine() {
    rock.free();
    paper.free();
    scissors.free();
    CloseWindow();
}

GameEngine::State GameEngine::get_state() { return current_state; }

bool GameEngine::is_running() { return !WindowShouldClose(); }

void GameEngine::update() { mouse_pos = GetMousePosition(); }
