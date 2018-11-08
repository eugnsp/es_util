cmake_minimum_required(VERSION 3.5)
project(es_util_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic -D_DEBUG)

add_library(es_util INTERFACE IMPORTED)
set_target_properties(es_util PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/../include")

file(GLOB_RECURSE TEST_SRC RELATIVE "${PROJECT_SOURCE_DIR}/src" ${PROJECT_SOURCE_DIR}/src/*.cpp)
list(SORT TEST_SRC)

foreach(CPP_FILE ${TEST_SRC})
	get_filename_component(F_NAME ${CPP_FILE} NAME_WE)
	get_filename_component(F_DIR ${CPP_FILE} DIRECTORY)
	add_executable("${F_DIR}_${F_NAME}" "src/${CPP_FILE}")
	target_link_libraries("${F_DIR}_${F_NAME}" es_util)
endforeach()

