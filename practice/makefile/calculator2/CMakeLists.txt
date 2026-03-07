cmake_minimum_required(VERSION 3.10)

project(Calculator C)

add_library(utils STATIC src/utils/*.c)

target_include_directories(utils PRIVATE include)

add_library(utils src/core/*.c)

add_executable(app src/main.c)