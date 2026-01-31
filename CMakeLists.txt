cmake_minimum_required(VERSION 3.28.3)

project(lsl)

add_library(lsl STATIC src/random.cpp src/utility.cpp)

add_library(lsl::lsl ALIAS lsl)

target_include_directories(lsl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(lsl PUBLIC cxx_std_20)

