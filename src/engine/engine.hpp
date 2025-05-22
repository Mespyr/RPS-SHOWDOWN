#pragma once

#include <raylib.h>

#include <algorithm>
#include <string>

class Sprite {
  public:
    void init(const std::string& file_path, Rectangle src, Rectangle dest);
    void free();
    ~Sprite();

    // setters
    void set_pos(Vector2 pos);
    void set_size(Vector2 size);

    // getters
    Vector2   get_pos();
    Rectangle get_dest();

    void draw();

  private:
    Rectangle source, destination;
    Texture2D texture;
    bool      freed = false;
};

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
