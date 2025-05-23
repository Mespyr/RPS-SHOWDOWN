#include <raylib.h>

#include "engine/engine.hpp"

int main() {
    GameEngine game("RPS SHOWDOWN", 1280, 720);

    while (game.is_running()) {
        game.update();
        BeginDrawing();
        game.clear_screen();

        switch (game.get_state()) {
        case GameEngine::State::GET_PLAYER_CHOICE:
            game.draw_get_player_choice();
            break;
        case GameEngine::State::TRANSITION_TO_AI_CHOICE: break;
        case GameEngine::State::GET_AI_CHOICE: break;
        }

        // game render sequence
        game.draw_HUD();
        EndDrawing();
    }

    return 0;
}
