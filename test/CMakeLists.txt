cmake_minimum_required(VERSION 3.5)
project(es_util_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic -march=native -m64 -D_DEBUG)

add_library(googletest UNKNOWN IMPORTED)
set_target_properties(googletest PROPERTIES
	IMPORTED_LOCATION "/home/es/lib/google/googletest/googletest/build/lib/libgtest.a"
	INTERFACE_INCLUDE_DIRECTORIES "/home/es/lib/google/googletest/googletest/include")

add_executable(sample1 sample1.cc sample1_unittest.cc gtest_main.cc)
target_link_libraries(sample1 googletest pthread)
