#pragma once
namespace Display {
void Help();
void Args(int argc, char* argv[]);
void RollResult(int num_dice, int die_sides, int result);
void PercentResult(bool success);
}