#include "engine.hpp"

#include <iostream>

void GameEngine::clear_screen() { ClearBackground(LIGHTGRAY); }

void GameEngine::draw_HUD() {
    int font_height = 20;
    int line_height = font_height + 5;
    int gap = 15;
    DrawText("High Score: 0", gap, gap, 20, RED);
    DrawText("Score: 0", gap, line_height + gap, 20, BLUE);
}

void GameEngine::draw_player_choices() {
	int text_width = MeasureText("Choose Your Move...", 30);
    DrawText("Choose Your Move...", (width - text_width)/2, 100, 30, BLACK);

    bool hovering_over_rock = collision_point_rect(mouse_pos, rock.get_dest());
    bool hovering_over_paper =
        collision_point_rect(mouse_pos, paper.get_dest());
    bool hovering_over_scissors =
        collision_point_rect(mouse_pos, scissors.get_dest());

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (hovering_over_rock) std::cout << "rock" << std::endl;
		else if (hovering_over_paper) std::cout << "paper" << std::endl;
		else if (hovering_over_scissors) std::cout << "scissors" << std::endl;
	}

    float   thirds = (width - 100) / 3;
    Vector2 rock_pos = {50, rock.get_pos().y};
    Vector2 paper_pos = {50 + thirds, paper.get_pos().y};
    Vector2 scissors_pos = {width - 50 - thirds, scissors.get_pos().y};

    // check hovering of sprites and adjust position accordingly
    if (hovering_over_rock)
        rock_pos.y = std::max<float>({350, rock_pos.y - 3});
    else
        rock_pos.y = 400;

    if (hovering_over_paper)
        paper_pos.y = std::max<float>({350, paper_pos.y - 3});
    else
        paper_pos.y = 400;

    if (hovering_over_scissors)
        scissors_pos.y = std::max<float>({350, scissors_pos.y - 3});
    else
        scissors_pos.y = 400;

    rock.set_pos(rock_pos);
    paper.set_pos(paper_pos);
    scissors.set_pos(scissors_pos);

    rock.draw();
    paper.draw();
    scissors.draw();
}
