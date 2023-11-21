cmake_minimum_required(VERSION 3.26)
project(piscine_cpp)

set(CMAKE_CXX_STANDARD 98)

include_directories(module00/ex01/includes)
include_directories(module01/ex00)
include_directories(module01/ex01)
include_directories(module01/ex03)
include_directories(module01/ex05)
include_directories(module02/ex00)
include_directories(module02/ex01)
include_directories(module02/ex02)
include_directories(module03/ex00)
include_directories(module03/ex01)
include_directories(module03/ex02)
include_directories(module04/ex00)
include_directories(module04/ex01)
include_directories(module04/ex02)
include_directories(module04/ex03)
include_directories(module05/ex00)

add_executable(
        piscine_cpp
        module09/ex00/RPN.hpp
        module09/ex00/main.cpp
)
