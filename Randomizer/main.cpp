#include "display.h"
#include "process.h"
int main(int argc, char* argv[]) {
  if (argc < 2) {
    Display::Args(argc, argv);
    Display::Help();
  } else {
    Process::AllArgs(argc, argv);
  }
}

