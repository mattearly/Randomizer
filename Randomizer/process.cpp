#include "process.h"
#include "display.h"
#include "random.h"
#include "types.h"
#include <algorithm>
#include "string_util.h"

f64 process_followup(Process::command_list in_cmd_type, std::string next_arg) {
  f64 return_value = 0;

  switch (in_cmd_type) {
  case Process::command_list::ROLL_DICE:
  {
    auto num1 = 0;
    if (isdigit(next_arg[0])) {
      num1 = std::atoi(next_arg.c_str());
    }
    auto d_pos = next_arg.find_first_of('d');
    if (d_pos == -1) {
      return_value = -1;
      break;
    }
    //auto last_index = next_arg.find_last_not_of("0123456789");
    auto part2_str = next_arg.substr(d_pos + 1);
    auto num2 = 0;
    if (isdigit(part2_str[0])) {
      num2 = std::atoi(part2_str.c_str());
    }
    if (num1 > 0 && num2 > 0) {
      auto result = 0;
      for (auto i = 0; i < num1; i++)
        result += Random::NTKR(1, num2);
      Display::RollResult(num1, num2, result);
      return_value = result;
    }
  }
  break;
  case Process::command_list::PERCENTAGE_CHANCE:
  {
    f64 num1 = 0.f;
    if (isdigit(next_arg[0])) {
      num1 = std::atof(next_arg.c_str());
    }
    auto d100f = Random::NTKR(0.f, 100.f);
    Display::PercentResult((num1 > d100f));
    return_value = d100f;
  }
  break;
  case Process::command_list::ODDS_CHANCE:
  {
    auto num1 = 0;
    if (isdigit(next_arg[0])) {
      num1 = std::atoi(next_arg.c_str());
    }
    auto d_pos = next_arg.find_first_of('n');
    //auto last_index = next_arg.find_last_not_of("0123456789");
    auto part2_str = next_arg.substr(d_pos + 1);
    auto num2 = 0;
    if (isdigit(part2_str[0])) {
      num2 = std::atoi(part2_str.c_str());
    }
    if (num1 > 0 && num2 > 0 && num1 < num2) {
      f64 your_chance = (f64)num1 / (f64)num2;
      your_chance *= 100;  // conver to percent chance
      auto rand_d100 = Random::NTKR(0.f, 100.f);
      Display::PercentResult((your_chance > rand_d100));
      return_value = (your_chance > rand_d100);
    }
  }
  break;
  default:
    break;
  }
  return return_value;
}

f64 Process::AllArgs(int argc, char* argv[]) {
  f64 return_result = 0.0;
  command_list cmd{ command_list::INVALID };

  // process first arg and make sure it is valid - looks for valid commands
  std::string tmp = Util::RemoveWhitespace(argv[1]);
  std::for_each(tmp.begin(), tmp.end(), [](char& c) { c = ::tolower(c); });  // make all lowercase

  if (tmp == "-r" || tmp == "--roll") {
    cmd = command_list::ROLL_DICE;
  } else if (tmp == "-p" || tmp == "--percent") {
    cmd = command_list::PERCENTAGE_CHANCE;
  } else if (tmp == "-o" || tmp == "--odds") {
    cmd = command_list::ODDS_CHANCE;
  } else {
    cmd = command_list::INVALID;
  }

  switch (cmd) {
  case command_list::INVALID:
    Display::Args(argc, argv);
    Display::Help();
    break;
  case command_list::ODDS_CHANCE:
  case command_list::PERCENTAGE_CHANCE:
  case command_list::ROLL_DICE:
  {
    // Process second arg along with first command
    std::string tmp2(Util::RemoveWhitespace(argv[2])); // save arg as a temporary string for processing
    std::for_each(tmp2.begin(), tmp2.end(), [](char& c) { c = ::tolower(c); });  // make all lowercase
    return_result = process_followup(cmd, tmp2);
  }
  break;
  default:
    break;
  }

  return return_result;
}
