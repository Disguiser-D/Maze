cmake_minimum_required(VERSION 3.15)
project(maze)

set(CMAKE_CXX_STANDARD 14)

add_executable(maze main.cpp include/loadmaze.h include/allmazeaccess.h include/createmaze.h)