#pragma once
#include <string>
#include "types.h"
namespace Process {
enum class command_list { INVALID, ROLL_DICE, PERCENTAGE_CHANCE, ODDS_CHANCE, HELP };
f64 AllArgs(int argc, char* argv[]);
}
