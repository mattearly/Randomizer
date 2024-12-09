#pragma once
namespace Display {
void Help();
void Args(int argc, char* argv[]);
void RollResult(int num_dice, int die_sides, int result);  // not used,  but leaving here
void RollResult(int num_dice, int die_sides, int* results);
void PercentResult(bool success);
}