cmake_minimum_required(VERSION 3.5)

project(treestp2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(treestp2 main.cpp inttree.h inttree.cpp)
