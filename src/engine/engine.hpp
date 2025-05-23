#pragma once

#include <raylib.h>

#include <algorithm>
#include <string>

#include "../sprite.hpp"

class GameEngine {
  public:
    GameEngine(const std::string& name, float width, float height);
    ~GameEngine();

    typedef enum { GET_PLAYER_MOVE, TRANSITION_TO_AI_MOVE, GET_AI_MOVE } State;

    // general
    State get_state();
    bool  is_running();
    void  update();

    // render
    void clear_screen();
    void draw_HUD();
    // states
    void draw_get_player_move();

    // collisions
    bool collision_point_rect(Vector2 point, Rectangle rect);

  private:
    const float width, height;
    Vector2     mouse_pos;
    State       current_state = GET_PLAYER_MOVE;

    Sprite rock;
    Sprite paper;
    Sprite scissors;
};
