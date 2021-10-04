cmake_minimum_required(VERSION 3.0)

project(usaco)

add_executable(usaco 2018-2019/2nd/Silver/problem3.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS usaco RUNTIME DESTINATION bin)
