cmake_minimum_required(VERSION 3.15)
project(maze)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=GBK -finput-charset=UTF-8")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")


add_executable(maze main.cpp include/loadmaze.h include/allmazeaccess.h include/createmaze.h include/base.h)