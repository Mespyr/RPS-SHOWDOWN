#pragma once

#include <raylib.h>

#include <string>

class Sprite {
  public:
    void init(const std::string& file_path, Rectangle src, Rectangle dest,
              float rotation = 0.0);
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
    float     degrees_rotation = 0.0;
    Texture2D texture;
    bool      freed = false;
};
