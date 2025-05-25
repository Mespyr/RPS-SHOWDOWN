#include "rps_choices.hpp"

std::string to_string(RPS_Choice move) {
    switch (move) {
    case RPS_Choice::ROCK: return "Rock";
    case RPS_Choice::PAPER: return "Paper";
    case RPS_Choice::SCISSORS: return "Scissors";
    case RPS_Choice::NONE: return "Nothing";
    }
    return "Nothing";
}

RPS_Choice get_win_choice(RPS_Choice choice) {
    switch (choice) {
    case RPS_Choice::ROCK: return RPS_Choice::PAPER;
    case RPS_Choice::PAPER: return RPS_Choice::SCISSORS;
    case RPS_Choice::SCISSORS: return RPS_Choice::ROCK;
    case RPS_Choice::NONE: return RPS_Choice::NONE;
    }
    return RPS_Choice::NONE;
}

bool check_player_won(RPS_Choice player_choice, RPS_Choice AI_choice) {
    return player_choice == get_win_choice(AI_choice);
}
