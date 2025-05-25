#include "engine.hpp"

void GameEngine::draw_get_player_choice() {
    int text_width = MeasureText("Choose Your Move...", 40);
    DrawText("Choose Your Move...", (width - text_width) / 2, 100, 40, BLACK);

    bool hovering_over_rock = collision_point_rect(mouse_pos, rock.get_dest());
    bool hovering_over_paper =
        collision_point_rect(mouse_pos, paper.get_dest());
    bool hovering_over_scissors =
        collision_point_rect(mouse_pos, scissors.get_dest());

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (hovering_over_rock)
            player_choice = RPS_Choice::ROCK;
        else if (hovering_over_paper)
            player_choice = RPS_Choice::PAPER;
        else if (hovering_over_scissors)
            player_choice = RPS_Choice::SCISSORS;

        if (hovering_over_rock || hovering_over_paper || hovering_over_scissors)
            set_state(TRANSITION_TO_AI_CHOICE);
    }

    // split the screen into 3rds (minus padding on the edges)
    Vector2 rock_pos = rock.get_pos();
    Vector2 paper_pos = paper.get_pos();
    Vector2 scissors_pos = scissors.get_pos();

    // check hovering of sprites and adjust position accordingly
    if (hovering_over_rock)
        rock_pos.y = std::max<float>({340, rock_pos.y - 4});
    else
        rock_pos.y = 390;

    if (hovering_over_paper)
        paper_pos.y = std::max<float>({350, paper_pos.y - 4});
    else
        paper_pos.y = 400;

    if (hovering_over_scissors)
        scissors_pos.y = std::max<float>({340, scissors_pos.y - 4});
    else
        scissors_pos.y = 390;

    rock.set_pos(rock_pos);
    paper.set_pos(paper_pos);
    scissors.set_pos(scissors_pos);

    rock.draw();
    paper.draw();
    scissors.draw();
}

void GameEngine::draw_transition_to_ai_choice() {
    std::string text = "You Chose " + to_string(player_choice) + "...";
    int         text_width = MeasureText(text.c_str(), 40);
    DrawText(text.c_str(), (width - text_width) / 2, 100, 40, BLACK);

    Vector2 rock_pos = rock.get_pos();
    Vector2 paper_pos = paper.get_pos();
    Vector2 scissors_pos = scissors.get_pos();

    if (player_choice == RPS_Choice::ROCK)
        rock_pos.y = 340;
    else
        rock_pos.y += 10;

    if (player_choice == RPS_Choice::PAPER)
        paper_pos.y = 350;
    else
        paper_pos.y += 10;

    if (player_choice == RPS_Choice::SCISSORS)
        scissors_pos.y = 340;
    else
        scissors_pos.y += 10;

    rock.set_pos(rock_pos);
    paper.set_pos(paper_pos);
    scissors.set_pos(scissors_pos);

    rock.draw();
    paper.draw();
    scissors.draw();

    if ((rock_pos.y > height) || (paper_pos.y > height) ||
        (scissors_pos.y > height))
        set_state(GET_AI_CHOICE);
}

void GameEngine::draw_get_ai_choice() {
    switch (player_choice) {
    case RPS_Choice::ROCK: rock.draw(); break;
    case RPS_Choice::PAPER: paper.draw(); break;
    case RPS_Choice::SCISSORS: scissors.draw(); break;
    case RPS_Choice::NONE: break;
    }

    Vector2 pos;
    float   final_y_pos = 0.0;

    switch (ai_choice) {
    case RPS_Choice::ROCK: {
        pos = ai_rock.get_pos();
        pos.y = std::min<float>({0.0, pos.y + 8});
        ai_rock.set_pos(pos);
        ai_rock.draw();
        break;
    }
    case RPS_Choice::PAPER: {
        pos = ai_paper.get_pos();
        pos.y = std::min<float>({-10.0, pos.y + 8});
        ai_paper.set_pos(pos);
        ai_paper.draw();
        final_y_pos = -10.0;
        break;
    }
    case RPS_Choice::SCISSORS: {
        pos = ai_scissors.get_pos();
        pos.y = std::min<float>({0.0, pos.y + 8});
        ai_scissors.set_pos(pos);
        ai_scissors.draw();
        break;
    }
    case RPS_Choice::NONE: break;
    }

    if (pos.y == final_y_pos) {
        if (check_player_won(player_choice, ai_choice))
            set_state(HANDLE_WIN);  // this is a precursor to YOU_WON_SCREEN
        else if (player_choice == ai_choice)
            set_state(YOU_TIED_SCREEN);
        else
            set_state(YOU_LOST_SCREEN);
    }

    std::string text = "The AI Chose " + to_string(ai_choice) + "...";
    int         text_width = MeasureText(text.c_str(), 40);
    DrawText(text.c_str(), (width - text_width) / 2, 100, 40, BLACK);
}

void GameEngine::draw_you_won_screen() {
    std::string text = "You Won!!";
    int         text_width = MeasureText(text.c_str(), 40);
    DrawText(text.c_str(), (width - text_width) / 2, 100, 40, DARKGREEN);

    float btn_width = MeasureText("Continue", 30) + 30;

    Rectangle continue_button = {(width / 2) - btn_width - 20, 300, btn_width,
                                 40};
    Rectangle quit_button = {(width / 2) + 20, 300, btn_width, 40};

    bool hovering_over_continue =
        collision_point_rect(mouse_pos, continue_button);
    bool hovering_over_quit = collision_point_rect(mouse_pos, quit_button);

    Color continue_button_color = GRAY;
    Color quit_button_color = GRAY;

    if (hovering_over_continue) continue_button_color = DARKGRAY;
    if (hovering_over_quit) quit_button_color = DARKGRAY;

    DrawRectanglePro(continue_button, {0, 0}, 0.0, continue_button_color);
    DrawRectanglePro(quit_button, {0, 0}, 0.0, quit_button_color);

    std::string continue_text = "Continue";
    int         continue_width = MeasureText(continue_text.c_str(), 30);
    DrawText(continue_text.c_str(), continue_button.x + 15,
             continue_button.y + 5, 30, WHITE);

    std::string quit_text = "Quit";
    int         quit_width = MeasureText(quit_text.c_str(), 30);
    DrawText(quit_text.c_str(), quit_button.x + 15, quit_button.y + 5, 30,
             WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (hovering_over_quit)
            quit = true;
        else if (hovering_over_continue) {
            reset_textures();
            set_state(GET_PLAYER_CHOICE);
        }
    }
}
void GameEngine::draw_you_tied_screen() {
    std::string text = "You Tied...";
    int         text_width = MeasureText(text.c_str(), 40);
    DrawText(text.c_str(), (width - text_width) / 2, 100, 40, BLACK);

    float btn_width = MeasureText("Continue", 30) + 30;

    Rectangle continue_button = {(width / 2) - btn_width - 20, 300, btn_width,
                                 40};
    Rectangle quit_button = {(width / 2) + 20, 300, btn_width, 40};

    bool hovering_over_continue =
        collision_point_rect(mouse_pos, continue_button);
    bool hovering_over_quit = collision_point_rect(mouse_pos, quit_button);

    Color continue_button_color = GRAY;
    Color quit_button_color = GRAY;

    if (hovering_over_continue) continue_button_color = DARKGRAY;
    if (hovering_over_quit) quit_button_color = DARKGRAY;

    DrawRectanglePro(continue_button, {0, 0}, 0.0, continue_button_color);
    DrawRectanglePro(quit_button, {0, 0}, 0.0, quit_button_color);

    std::string continue_text = "Continue";
    int         continue_width = MeasureText(continue_text.c_str(), 30);
    DrawText(continue_text.c_str(), continue_button.x + 15,
             continue_button.y + 5, 30, WHITE);

    std::string quit_text = "Quit";
    int         quit_width = MeasureText(quit_text.c_str(), 30);
    DrawText(quit_text.c_str(), quit_button.x + 15, quit_button.y + 5, 30,
             WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (hovering_over_quit)
            quit = true;
        else if (hovering_over_continue) {
            reset_textures();
            set_state(GET_PLAYER_CHOICE);
        }
    }
}
void GameEngine::draw_you_lost_screen() {
    std::string text = "You Lost :(";
    int         text_width = MeasureText(text.c_str(), 40);
    DrawText(text.c_str(), (width - text_width) / 2, 100, 40, RED);

    float btn_width = MeasureText("Try Again", 30) + 30;

    Rectangle try_again_button = {(width / 2) - btn_width - 20, 300, btn_width,
                                  40};
    Rectangle quit_button = {(width / 2) + 20, 300, btn_width, 40};

    bool hovering_over_try_again =
        collision_point_rect(mouse_pos, try_again_button);
    bool hovering_over_quit = collision_point_rect(mouse_pos, quit_button);

    Color try_again_button_color = GRAY;
    Color quit_button_color = GRAY;

    if (hovering_over_try_again) try_again_button_color = DARKGRAY;
    if (hovering_over_quit) quit_button_color = DARKGRAY;

    DrawRectanglePro(try_again_button, {0, 0}, 0.0, try_again_button_color);
    DrawRectanglePro(quit_button, {0, 0}, 0.0, quit_button_color);

    std::string try_again_text = "Try Again";
    int         try_again_width = MeasureText(try_again_text.c_str(), 30);
    DrawText(try_again_text.c_str(), try_again_button.x + 15,
             try_again_button.y + 5, 30, WHITE);

    std::string quit_text = "Quit";
    int         quit_width = MeasureText(quit_text.c_str(), 30);
    DrawText(quit_text.c_str(), quit_button.x + 15, quit_button.y + 5, 30,
             WHITE);

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        if (hovering_over_quit)
            quit = true;
        else if (hovering_over_try_again) {
            reset_textures();
            set_state(HANDLE_RESET);
        }
    }
}
