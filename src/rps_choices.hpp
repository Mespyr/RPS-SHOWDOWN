#pragma once

#include <string>

typedef enum { ROCK, PAPER, SCISSORS, NONE } RPS_Choice;

std::string to_string(RPS_Choice choice);
RPS_Choice  get_win_choice(RPS_Choice choice);
bool        check_player_won(RPS_Choice player_choice, RPS_Choice AI_choice);
