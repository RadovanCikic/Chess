cmake_minimum_required(VERSION 3.26)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Chess
        ChessFigure.cpp
        ChessFigure.h
        test.cpp)
