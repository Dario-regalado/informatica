cmake_minimum_required(VERSION 3.16.3)

project(rotate
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(rotate
    dependencies.cc
    dependencies.h
    rotate.cc
    )

target_compile_features(rotate PRIVATE cxx_std_17)
target_compile_options(rotate PRIVATE -Wall)
