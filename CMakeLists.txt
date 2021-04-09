cmake_minimum_required(VERSION 3.10.2)

project(route_create CXX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk+-2.0)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})
add_definitions(${GTK_LIBRARY_DIRS})

add_executable(route_main route_main.cpp route_gui.cpp route_header.cpp)
target_link_libraries(route_main ${GTK_LIBRARIES})
