cmake_minimum_required(VERSION 3.16.3)

project(vowels-and-consonants
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(vowels-and-consonants
    dependencies.cc
    dependencies.h
    vowels-and-consonants.cc
    )

target_compile_features(vowels-and-consonants PRIVATE cxx_std_17)
target_compile_options(vowels-and-consonants PRIVATE -Wall)
