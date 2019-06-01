cmake_minimum_required(VERSION 3.7)
project(es_util VERSION 1.0 DESCRIPTION "Utilities library")

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE CPP_FILES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(es_util STATIC "${CPP_FILES}")
target_include_directories(es_util PUBLIC "include")
target_compile_features(es_util PUBLIC cxx_std_17)
target_compile_options(es_util PRIVATE -Wall -Wpedantic -Wextra -Werror=return-type -m64 -march=native 
					   $<$<CONFIG:DEBUG>:-O0 -g> $<$<CONFIG:RELEASE>:-Wno-unused-parameter -Wno-deprecated-declarations -O3 -DNDEBUG>)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	target_compile_options(es_util PRIVATE -Wno-psabi)
endif()
