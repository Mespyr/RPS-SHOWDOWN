#pragma once

#include <raylib.h>

#include <algorithm>
#include <string>

#include "../game_data/game_data.hpp"
#include "../rps_choices.hpp"
#include "../sprite.hpp"

class GameEngine {
  public:
    GameEngine(const std::string& name, float width, float height);
    ~GameEngine();

    typedef enum {
        GET_PLAYER_CHOICE,
        TRANSITION_TO_AI_CHOICE,
        GET_AI_CHOICE,

        HANDLE_WIN, // single pass for score incrementation
        YOU_WON_SCREEN,

        YOU_TIED_SCREEN,
        YOU_LOST_SCREEN,
		HANDLE_RESET // single pass to reset score before trying again
    } State;

    // general
    State get_state();
    void  set_state(State state);

    bool is_running();
    void update();
    void set_ai_choice(RPS_Choice choice);
    void reset_textures();

    // render
    void clear_screen();
    void draw_HUD(GameData& data);

    // states
    void draw_get_player_choice();
    void draw_transition_to_ai_choice();
    void draw_get_ai_choice();
    void draw_you_won_screen();
    void draw_you_tied_screen();
    void draw_you_lost_screen();

    // collisions
    bool collision_point_rect(Vector2 point, Rectangle rect);

  private:
    bool        quit = false;
    const float width, height;
    Vector2     mouse_pos;
    State       current_state = GET_PLAYER_CHOICE;

    RPS_Choice player_choice = RPS_Choice::NONE;
    RPS_Choice ai_choice = RPS_Choice::NONE;

    Sprite rock;
    Sprite paper;
    Sprite scissors;

    Sprite ai_rock;
    Sprite ai_paper;
    Sprite ai_scissors;
};
