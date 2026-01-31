cmake_minimum_required(VERSION 3.28.3)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(lsl)

add_library(lsl STATIC src/random.cpp src/utility.cpp)

add_library(lsl::lsl ALIAS lsl)

target_include_directories(lsl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(lsl PUBLIC cxx_std_20)

#compile command: CC=clang CXX=clang++ cmake -S . -B build -G Ninja