# CMakeList.txt : CMake project for Randomizer, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Randomizer "main.cpp" "display.cpp" "display.h" "process.h" "process.cpp" "random.cpp" "random.h" "types.h" "string_util.cpp" "string_util.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Randomizer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
install(TARGETS Randomizer)
