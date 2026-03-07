cmake_minimum_required(VERSION 3.10)

project(Mymath exmaple C)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(calculator ${SOURCES})