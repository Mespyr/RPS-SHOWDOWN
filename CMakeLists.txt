cmake_minimum_required(VERSION 3.20)
project(RPS_SHOWDOWN LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Raylib
find_package(raylib REQUIRED)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Executable
add_executable(RPS_SHOWDOWN ${SOURCES})

# Link raylib (and any dependencies raylib needs)
target_link_libraries(RPS_SHOWDOWN raylib)
