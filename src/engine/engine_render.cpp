#include "engine.hpp"

void GameEngine::clear_screen() { ClearBackground(LIGHTGRAY); }

void GameEngine::draw_HUD(GameData& data) {
    int         font_height = 24;
    int         line_height = font_height + 5;
    int         gap = 15;
    std::string highscore_text =
        "High Score: " + std::to_string(data.get_high_score());
    std::string score_text = "Score: " + std::to_string(data.get_score());
    DrawText(highscore_text.c_str(), gap, gap, font_height, RED);
    DrawText(score_text.c_str(), gap, line_height + gap, font_height, BLUE);
}
