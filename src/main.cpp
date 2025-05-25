#include <raylib.h>

#include "engine/engine.hpp"
#include "game_data/game_data.hpp"

int main() {
    GameEngine game("RPS SHOWDOWN", 1280, 720);
    GameData   data;

    while (game.is_running()) {
        game.update();
        BeginDrawing();
        game.clear_screen();

        switch (game.get_state()) {
        case GameEngine::State::GET_PLAYER_CHOICE:
            game.draw_get_player_choice();
            break;
        case GameEngine::State::TRANSITION_TO_AI_CHOICE:
            game.draw_transition_to_ai_choice();
            break;
        case GameEngine::State::GET_AI_CHOICE:
            game.set_ai_choice(data.generate_ai_choice());
			data.add_player_choice(game.get_player_choice());
            game.set_state(GameEngine::State::DRAW_AI_CHOICE);
            game.draw_get_ai_choice();
            break;
        case GameEngine::State::DRAW_AI_CHOICE:
			game.draw_get_ai_choice();
			break;

        case GameEngine::State::HANDLE_WIN:
            data.inc_score();  // sets point gained last round to true
            game.set_state(GameEngine::State::YOU_WON_SCREEN);
            game.draw_you_won_screen();
            break;
        case GameEngine::State::YOU_WON_SCREEN:
            game.draw_you_won_screen();
            break;

        case GameEngine::State::YOU_TIED_SCREEN:
            data.set_point_gained_last_round(false);
            game.draw_you_tied_screen();
            break;

        case GameEngine::State::YOU_LOST_SCREEN:
            game.draw_you_lost_screen();
            break;
        case GameEngine::State::HANDLE_RESET:
            data.reset();  // sets point gained last round to false
            game.set_state(GameEngine::State::GET_PLAYER_CHOICE);
            game.draw_get_player_choice();
            break;
        }

        // game render sequence
        game.draw_HUD(data);
        EndDrawing();
    }

    data.write_save_data();

    return 0;
}
