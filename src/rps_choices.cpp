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
