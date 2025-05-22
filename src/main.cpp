#include <raylib.h>

#include "engine/engine.hpp"

int main() {
    GameEngine game("RPS SHOWDOWN", 1280, 720);

    while (game.is_running()) {
        game.update();

        BeginDrawing();
        game.clear_screen();
        game.draw_player_choices();
        // game render sequence
        game.draw_HUD();
        EndDrawing();
    }

    return 0;
}
