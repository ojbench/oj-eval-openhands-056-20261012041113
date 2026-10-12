cmake_minimum_required(VERSION 3.10)

# Project name
project(m0ss1_attendance)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags for optimization
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -Wextra")

# Add executable
add_executable(code main.cpp)

# Ensure the executable is named 'code' as required