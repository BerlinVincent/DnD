cmake_minimum_required(VERSION 3.0.0)
project (DnD)

include(CTest)
enable_testing()

add_executable(DnD ./DungeonsAndDragons/main.cpp)

set_property(TARGET DnD PROPERTY CXX_STANDARD 20)