#pragma once
#include <string>
namespace Process {
enum class command_list { INVALID, ROLL_DICE, PERCENTAGE_CHANCE, ODDS_CHANCE, HELP };
void AllArgs(int argc, char* argv[]);
}
