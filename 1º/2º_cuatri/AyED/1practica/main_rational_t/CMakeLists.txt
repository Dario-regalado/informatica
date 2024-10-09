cmake_minimum_required(VERSION 3.16.3)

project(main_rational_t
    VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(main_rational_t
    main_rational_t.cc
    rational_t.cc
    rational_t.h
    )

target_compile_features(main_rational_t PRIVATE cxx_std_17)
target_compile_options(main_rational_t PRIVATE -Wall)
