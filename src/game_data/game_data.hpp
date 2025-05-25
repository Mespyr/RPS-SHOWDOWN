#pragma once

#include <cstdint>
#include <string>
#include <fstream>
#include <vector>

#include "../rps_choices.hpp"

class GameData {
  private:
    const std::string       SAVE_FILE_NAME = "Rush_SavaData";
    uint32_t                score = 0;
    uint32_t                high_score = 0;
    std::vector<RPS_Choice> player_previous_choices;
    bool                    point_gained_last_round = false;

  public:
    bool game_over = false;

    GameData();
    void write_save_data();
	uint32_t get_high_score();
	uint32_t get_score();
	void add_player_choice(RPS_Choice choice);

	void inc_score();
	void reset();

	void set_point_gained_last_round(bool v);

    RPS_Choice generate_ai_choice();
};
