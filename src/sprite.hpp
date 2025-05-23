#pragma once

#include <raylib.h>

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
