#pragma once

#include <raylib.h>

#include <algorithm>
#include <string>

#include "../rps_choices.hpp"
#include "../sprite.hpp"

class GameEngine {
  public:
    GameEngine(const std::string& name, float width, float height);
    ~GameEngine();

    typedef enum { GET_PLAYER_CHOICE, TRANSITION_TO_AI_CHOICE, GET_AI_CHOICE} State;

    // general
    State get_state();
    bool  is_running();
    void  update();

    // render
    void clear_screen();
    void draw_HUD();
    // states
    void draw_get_player_choice();
    void draw_transition_to_ai_choice();

    // collisions
    bool collision_point_rect(Vector2 point, Rectangle rect);

  private:
    const float width, height;
    Vector2     mouse_pos;
    State       current_state = GET_PLAYER_CHOICE;
    RPS_Choice  player_choice = RPS_Choice::NONE;

    Sprite rock;
    Sprite paper;
    Sprite scissors;
};
