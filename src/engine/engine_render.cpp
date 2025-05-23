#include "engine.hpp"

void GameEngine::clear_screen() { ClearBackground(LIGHTGRAY); }

void GameEngine::draw_HUD() {
    int font_height = 24;
    int line_height = font_height + 5;
    int gap = 15;
    DrawText("High Score: 0", gap, gap, font_height, RED);
    DrawText("Score: 0", gap, line_height + gap, font_height, BLUE);
}

void GameEngine::draw_get_player_choice() {
    int text_width = MeasureText("Choose Your Move...", 40);
    DrawText("Choose Your Move...", (width - text_width) / 2, 100, 40, BLACK);

    bool hovering_over_rock = collision_point_rect(mouse_pos, rock.get_dest());
    bool hovering_over_paper =
        collision_point_rect(mouse_pos, paper.get_dest());
    bool hovering_over_scissors =
        collision_point_rect(mouse_pos, scissors.get_dest());

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        // TODO: when adding code for saves and the AI-algorithm, replace cout
        // with setting the player's choice.
        if (hovering_over_rock)
            player_choice = RPS_Choice::ROCK;
        else if (hovering_over_paper)
            player_choice = RPS_Choice::PAPER;
        else if (hovering_over_scissors)
            player_choice = RPS_Choice::SCISSORS;

        if (hovering_over_rock || hovering_over_paper || hovering_over_scissors)
            current_state = TRANSITION_TO_AI_CHOICE;
    }

    // split the screen into 3rds (minus padding on the edges)
    float   thirds = (width - 75) / 3;
    Vector2 rock_pos = {37, rock.get_pos().y};
    Vector2 paper_pos = {37 + thirds, paper.get_pos().y};
    Vector2 scissors_pos = {37 + (thirds * 2), scissors.get_pos().y};

    // check hovering of sprites and adjust position accordingly
    if (hovering_over_rock)
        rock_pos.y = std::max<float>({350, rock_pos.y - 4});
    else
        rock_pos.y = 390;

    if (hovering_over_paper)
        paper_pos.y = std::max<float>({350, paper_pos.y - 4});
    else
        paper_pos.y = 400;

    if (hovering_over_scissors)
        scissors_pos.y = std::max<float>({350, scissors_pos.y - 4});
    else
        scissors_pos.y = 390;

    rock.set_pos(rock_pos);
    paper.set_pos(paper_pos);
    scissors.set_pos(scissors_pos);

    rock.draw();
    paper.draw();
    scissors.draw();
}

void draw_transition_to_ai_move();
