cmake_minimum_required(VERSION 3.15)

add_library(core src/*.c)

target_link_libraries(core PRIVATE utils)

# Compile flags
target_compile_options(core PRIVATE -Wall -Wextra -Werror)

target_include_directories(core PUBLIC include)