cmake_minimum_required(VERSION 3.25)
project(RubicksCubeSolve)

set(CMAKE_CXX_STANDARD 14)

add_executable(RubicksCubeSolve main.cpp GenericRubiksCube.cpp GenericRubiksCube.h RubiksCube3dArray.cpp)
