#include "display.h"
#include "string_util.h"
#include <iostream>
void Display::Help() {
  std::cout
    << "MJE's Randomizer Usage: \n"
    << " command       args                               description\n"
    << " -------       ----                               -----------\n"
    << "-p, --percent [x; where x<100]                  | Try for a % success chance. ex \"-p 50.0\"\n"
    << "-o, --odds    [x; where x<y] in [y; where y>x]  | Odds. ex \"-o 1in10\"\n"
    << "-r, --roll    [x]d[y]; where x&y are ints > 0   | Roll dice. ex \"-r 3d6\"\n";
}

void Display::Args(int argc, char* argv[]) {
  std::cout << "Args passed in:\n";
  int at = 0;
  while (at < argc) {
    std::cout << "argv[" << at << "] = " << Util::RemoveWhitespace(argv[at]) << '\n';
    at++;
  }
}

void Display::RollResult(int num_dice, int die_sides, int result) {  // not used, but leaving here
  std::cout
    << "Rolled: " << num_dice << "d" << die_sides << '\n'
    << "    Result = " << result << '\n';
  std::cout << "old version, total only\n";
}

void Display::RollResult(int num_dice, int die_sides, int* results) {
    std::cout
        << "Rolled: " << num_dice << "d" << die_sides << '\n';
    int sum = 0;
    for (int i = 0; i < num_dice; ++i) {
        std::cout << "roll" << i << ": " << results[i] << '\n';
        sum += results[i];
    }
    std::cout << "Added Total: " << sum << '\n';
}

void Display::PercentResult(bool success) {
  std::cout 
    << "Win: " << std::boolalpha << success << '\n';
}
