#include <raylib.h>

int main() {
	InitWindow(1280, 720, "RPS SHOWDOWN");

	Texture2D rock_texture = LoadTexture("assets/rock.png");
	Texture2D paper_texture = LoadTexture("assets/paper.png");
	Texture2D scissors_texture = LoadTexture("assets/scissors.png");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(DARKBLUE);
		EndDrawing();
	}

	UnloadTexture(rock_texture);
	UnloadTexture(paper_texture);
	UnloadTexture(scissors_texture);
	CloseWindow();
	return 0;
}
