cmake_minimum_required(VERSION 3.10)

set(This DnDMain)

find_package(Curses REQUIRED)

set(Sources
    main.cpp
)

add_executable(${This} ${Sources})

target_link_libraries(${This}
    PUBLIC
    ${CURSES_LIBRARIES}
    DnD
)

target_include_directories(${This}
    PUBLIC
    ${CURSES_INCLUDE_DIR}
)