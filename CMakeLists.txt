cmake_minimum_required(VERSION 3.6)

set(This DnD)

project(${This} C CXX)

# Set C++ standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(CTest)
enable_testing()

# add_subdirectory(DungeonsAndDragons)

set(Headers
    DungeonsAndDragons/Framework/entities/Entity.hpp
    DungeonsAndDragons/Framework/entities/Player.hpp

    DungeonsAndDragons/Framework/game_engine/Action.hpp
    DungeonsAndDragons/Framework/game_engine/Game.hpp
    DungeonsAndDragons/Framework/game_engine/Renderer.hpp
    DungeonsAndDragons/Framework/game_engine/Scenes.hpp

    DungeonsAndDragons/Framework/statistics/Alignment.hpp
    DungeonsAndDragons/Framework/statistics/Attacks_and_Spells.hpp
    DungeonsAndDragons/Framework/statistics/Attribute.hpp
    DungeonsAndDragons/Framework/statistics/Character_Class.hpp
    DungeonsAndDragons/Framework/statistics/Skill.hpp

    DungeonsAndDragons/Framework/CharacterCreator/CreationEngine.hpp

    DungeonsAndDragons/Framework/inclusions.hpp
)

set(Sources
    DungeonsAndDragons/Framework/entities/Entity.cpp
    DungeonsAndDragons/Framework/entities/Player.cpp

    DungeonsAndDragons/Framework/game_engine/Action.cpp
    DungeonsAndDragons/Framework/game_engine/Game.cpp
    DungeonsAndDragons/Framework/game_engine/Scenes.cpp

    DungeonsAndDragons/Framework/statistics/Attacks_and_Spells.cpp
    DungeonsAndDragons/Framework/statistics/Attribute.cpp
    DungeonsAndDragons/Framework/statistics/Skill.cpp

    DungeonsAndDragons/Framework/CharacterCreator/CreationEngine.cpp

    DungeonsAndDragons/Framework/inclusions.hpp
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Game Target

add_executable(dnd ${Sources} DungeonsAndDragons/main.cpp)
target_link_libraries(dnd ${CURSES_LIBRARIES})


# Test Target

# For Windows: Prevent overiding parent project's compiler/linker settings
set(gtest_force_shared_crt IN CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(dnd_testing EXCLUDE_FROM_ALL ${Sources} tests/UnitTests.cpp)
target_link_libraries(dnd_testing PUBLIC gtest_main ${CURSES_LIBRARIES})
add_dependencies(tests dnd_testing)

add_custom_target(tests)
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)

