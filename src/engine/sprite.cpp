#include "engine.hpp"

void Sprite::init(const std::string& file_path, Rectangle src, Rectangle dest) {
    source = src;
    destination = dest;
    texture = LoadTexture(file_path.c_str());
}

void Sprite::free() {
    UnloadTexture(texture);
    freed = true;
}

Sprite::~Sprite() {
    if (!freed) free();
}

void Sprite::set_pos(Vector2 pos) {
    destination.x = pos.x;
    destination.y = pos.y;
}

void Sprite::set_size(Vector2 size) {
    destination.width = size.x;
    destination.height = size.y;
}

void Sprite::draw() {
    DrawTexturePro(texture, source, destination, {0, 0}, 0.0, WHITE);
}

Vector2 Sprite::get_pos() { return {destination.x, destination.y}; }

Rectangle Sprite::get_dest() { return destination; }
