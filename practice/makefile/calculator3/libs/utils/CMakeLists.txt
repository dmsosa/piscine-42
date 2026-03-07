cmake_minimum_required(VERSION 3.15)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(utils src/*.c)

target_include_directories(utils PUBLIC include)

# Compile flags
target_compile_options(utils PRIVATE -Wall -Wextra -Werror)

# install(DIRECTORY include/ DESTINATION include)