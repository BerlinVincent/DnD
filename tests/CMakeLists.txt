cmake_minimum_required(VERSION 3.10)

set(This DnDTests)

# gtest for unit testing
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

# For Windows: Prevent ovveriding parent project's compiler/linker settings
set(gtest_force_shared_crt IN CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(Sources
    UnitTests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    DnD
)

add_test(
    NAME ${This}
    COMMAND ${This}
)