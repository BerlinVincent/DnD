cmake_minimum_required(VERSION 3.10)

set(This DnDMain)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(Sources
    main.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    ${CURSES_LIBRARIES}
    DnD
)

add_test(
    NAME ${This}
    COMMAND ${This}
)