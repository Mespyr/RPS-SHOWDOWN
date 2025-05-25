#include "game_data.hpp"

GameData::GameData() {
    std::fstream save_file(SAVE_FILE_NAME, std::ios_base::in);
    // if the save file exists, read data
    // else create a new save file
    if (save_file.good())
        save_file >> high_score;
    else
        write_save_data();
}

void GameData::write_save_data() {
    std::ofstream save_file(SAVE_FILE_NAME);
    if (score > high_score) high_score = score;
    save_file << high_score << std::endl;
}

uint32_t GameData::get_high_score() {
	return high_score;
}
uint32_t GameData::get_score() {
	return score;
}


void GameData::add_player_choice(RPS_Choice choice) {
	player_previous_choices.push_back(choice);
}

void GameData::inc_score() {
	point_gained_last_round = true;
	score++;
	if (score > high_score) high_score = score;
}

void GameData::reset() {
	point_gained_last_round = false;
	if (score > high_score) high_score = score;
	score = 0;
	player_previous_choices.clear();
}

void GameData::set_point_gained_last_round(bool v) { point_gained_last_round = v; }
