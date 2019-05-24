cmake_minimum_required(VERSION 3.7)
project(es_util VERSION 1.0 DESCRIPTION "Utilities library")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "-Wall -Wpedantic -Wextra -Werror=return-type -m64 -march=native -fmax-errors=5")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-Wno-unused-parameter -Wno-deprecated-declarations -O3 -DNDEBUG")

file(GLOB_RECURSE CPP_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(es_util STATIC "${CPP_FILES}")
target_include_directories(es_util PUBLIC "include")
