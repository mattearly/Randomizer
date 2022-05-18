#include "process.h"
#include "display.h"
#include "random.h"
#include "types.h"

void koff(Process::command_list val1, std::string val2) {
  switch (val1) {
  case Process::command_list::HELP:
    break;
  case Process::command_list::ROLL_DICE:
  {
    auto num1 = 0;
    if (isdigit(val2[0])) {
      num1 = std::atoi(val2.c_str());
    }
    auto d_pos = val2.find_first_of('d');
    auto last_index = val2.find_last_not_of("0123456789");
    auto part2_str = val2.substr(d_pos + 1);
    auto num2 = 0;
    if (isdigit(part2_str[0])) {
      num2 = std::atoi(part2_str.c_str());
    }
    if (num1 > 0 && num2 > 0) {
      auto result = 0;
      for (auto i = 0; i < num1; i++)
        result += Random::NTKR(1, num2);
      Display::RollResult(num1, num2, result);
    }
  }
  break;
  case Process::command_list::PERCENTAGE_CHANCE:
  {
    f64 num1 = 0.f;
    if (isdigit(val2[0])) {
      num1 = std::atof(val2.c_str());
    }
    auto d100f = Random::NTKR(0.f, 100.f);
    Display::PercentResult((num1 > d100f));

  }
  break;
  case Process::command_list::ODDS_CHANCE:
  {
    auto num1 = 0;
    if (isdigit(val2[0])) {
      num1 = std::atoi(val2.c_str());
    }
    auto d_pos = val2.find_first_of('n');
    auto last_index = val2.find_last_not_of("0123456789");
    auto part2_str = val2.substr(d_pos + 1);
    auto num2 = 0;
    if (isdigit(part2_str[0])) {
      num2 = std::atoi(part2_str.c_str());
    }
    if (num1 > 0 && num2 > 0 && num1 < num2) {
      f64 oddsin100 = (f64)num2 / (f64)num1;
      auto d100f = Random::NTKR(0.f, 100.f);
      Display::PercentResult((num1 > d100f));
    }
  }
  break;
  default:
    break;
  }
}

void Process::AllArgs(int argc, char* argv[]) {
  command_list cmd{ command_list::INVALID };

  for (auto count = 1; count < argc; count++) {
    std::string tmp(argv[count]);
    tmp.erase(std::remove_if(tmp.begin(), tmp.end(), ::isspace), tmp.end());

    if (cmd != command_list::INVALID) {
      koff(cmd, tmp);
      break;
    } else {
      if (tmp == "-r") {
        cmd = command_list::ROLL_DICE;
      } else if (tmp == "-p") {
        cmd = command_list::PERCENTAGE_CHANCE;
      } else if (tmp == "-o") {
        cmd = command_list::ODDS_CHANCE;
      } else if (tmp == "-h") {
        cmd = command_list::HELP;
        Display::Help();
        break;
      } else {
        cmd = command_list::INVALID;
        Display::Args(argc, argv);
        Display::Help();
        break;
      }
    }
  }
}
