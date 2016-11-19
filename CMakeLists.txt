set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
cmake_minimum_required(VERSION 3.5)
add_definitions("-Wall -std=c++14")
add_executable(kehomework src/main.cpp src/characterrecognizer/featurecalculator.cpp)
