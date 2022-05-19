#include "string_util.h"
std::string Util::RemoveWhitespace(const char* wide_boi) {
  std::string wut(wide_boi);
  wut.erase(std::remove_if(wut.begin(), wut.end(), ::isspace), wut.end());
  return wut;
}