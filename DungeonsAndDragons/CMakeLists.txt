cmake_minimum_required(VERSION 3.10)

set(This DnDMain)

set(Sources
    main.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    DnD
)