cmake_minimum_required(VERSION 3.0)

project(usaco)

add_executable(usaco 2015-2016/1st/Silver/problem3.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

install(TARGETS usaco RUNTIME DESTINATION bin)
