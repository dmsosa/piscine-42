cmake_minimum_required(VERSION 3.15)
project(calculator VERSION 1.0 LANGUAGES C)

# Set C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Default install prefix
if(NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX /usr CACHE PATH "Default install prefix")
endif()

message(STATUS "Source directory is: ${CMAKE_SOURCE_DIR}")
message(STATUS "Build directory for calculator app is: ${CMAKE_BINARY_DIR}")

add_subdirectory(libs/core)
add_subdirectory(libs/utils)

add_executable(calculator src/*.c)

target_link_libraries(calculator PUBLIC core)

# Compile flags
target_compile_options(calculator PRIVATE -Wall -Wextra -Werror)

install(TARGETS calculator DESTINATION bin)
# install(DIRECTORY include/ DESTINATION include)