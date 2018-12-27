cmake_minimum_required(VERSION 3.5)
project(es_util VERSION 1.0 DESCRIPTION "Utilities library")

add_library(es_util INTERFACE)
target_include_directories(es_util INTERFACE "include")
