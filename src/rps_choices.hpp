#pragma once

#include <string>

typedef enum { ROCK, PAPER, SCISSORS, NONE } RPS_Choice;

std::string to_string(RPS_Choice choice);
