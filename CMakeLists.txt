cmake_minimum_required(VERSION 3.21)
project(maze_solver)

set(CMAKE_CXX_STANDARD 14)

add_executable(maze_solver src/main.cpp src/Maze.cpp src/Maze.h src/Stack.cpp src/Stack.h src/Node.h src/FileIO.cpp src/FileIO.h)
