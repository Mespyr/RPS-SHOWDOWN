#include "engine.hpp"

GameEngine::GameEngine(const std::string& name, float width, float height)
    : width(width), height(height) {
    InitWindow(width, height, name.c_str());
    SetTargetFPS(15);

    float thirds = (width - 75) / 3;
    rock.init("assets/rock.png", {0, 0, 1086, 1086}, {37, 390, 400, 400});
    paper.init("assets/paper.png", {0, 0, 1086, 1086},
               {37 + thirds, 400, 400, 400});
    scissors.init("assets/scissors.png", {0, 0, 1086, 1086},
                  {37 + (2 * thirds), 390, 400, 400});

    ai_rock.init("assets/rock.png", {0, 0, 1086, -1086}, {37, -390, 400, 400});
    ai_paper.init("assets/paper.png", {0, 0, 1086, -1086},
                  {37 + thirds, -400, 400, 400});
    ai_scissors.init("assets/scissors.png", {0, 0, 1086, -1086},
                     {37 + (2 * thirds), -390, 400, 400});
}

GameEngine::~GameEngine() {
    rock.free();
    paper.free();
    scissors.free();
    ai_rock.free();
    ai_paper.free();
    ai_scissors.free();
    CloseWindow();
}

GameEngine::State GameEngine::get_state() { return current_state; }

void GameEngine::set_state(State state) { current_state = state; }

RPS_Choice GameEngine::get_player_choice() { return player_choice; }

bool GameEngine::is_running() { return !WindowShouldClose() && !quit; }

void GameEngine::update() { mouse_pos = GetMousePosition(); }

void GameEngine::set_ai_choice(RPS_Choice choice) { ai_choice = choice; }

void GameEngine::reset_textures() {
    float thirds = (width - 75) / 3;
    rock.set_pos({37, 390});
    paper.set_pos({37 + thirds, 400});
    scissors.set_pos({37 + (2 * thirds)});
    ai_rock.set_pos({37, -390});
    ai_paper.set_pos({37 + thirds, -400});
    ai_scissors.set_pos({37 + (2 * thirds), -390});
}
