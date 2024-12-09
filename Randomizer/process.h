#pragma once
#include <string>
#include "types.h"
const int ROLL_LIMIT = 128;
namespace Process {
enum class command_list { INVALID, ROLL_DICE, PERCENTAGE_CHANCE, ODDS_CHANCE };
f64 AllArgs(int argc, char* argv[]);
}
