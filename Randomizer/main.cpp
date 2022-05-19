#include "display.h"
#include "process.h"
int main(int argc, char* argv[]) {
  int result = -1;
  if (argc != 3) {
    Display::Help();
  } else {
    result = static_cast<int>(Process::AllArgs(argc, argv));
  }
  return result;
}

