#include "game_data.hpp"

// TODO: finish this function
RPS_Choice GameData::generate_ai_choice() {
    switch (player_previous_choices.size()) {
	case 0: return RPS_Choice::PAPER;
	case 1: {
        if (point_gained_last_round)
            return get_win_choice(player_previous_choices.front());
        else
            return player_previous_choices.front();
	}
	default:
		return RPS_Choice::ROCK;
	}
}
