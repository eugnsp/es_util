cmake_minimum_required(VERSION 3.5)
project(es_util_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic -march=native -D_DEBUG)

add_library(googletest STATIC IMPORTED)
set_target_properties(googletest PROPERTIES
	IMPORTED_LOCATION "/home/es/lib/google/googletest/googletest/build/lib/libgtest.a"
	INTERFACE_INCLUDE_DIRECTORIES "/home/es/lib/google/googletest/googletest/include")

add_library(es_util INTERFACE IMPORTED)
set_target_properties(es_util PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../include")

add_executable(es_util_test test.cpp)
target_link_libraries(es_util_test es_util googletest pthread)
