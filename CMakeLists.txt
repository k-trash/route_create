cmake_minimum_required(VERSION 3.10)

project(route_create CXX)
set(CMAKE_CXX_FLAGS "`pkg-config --cflags --libs gtk+-2.0`")

add_executable(route_main route_main.cpp route_gui.cpp route_header.cpp)
