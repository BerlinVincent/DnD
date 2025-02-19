#include <iostream>
#include <fstream>
#include "Framework/game_engine/Game.cpp"
#include "Framework/CharacterCreator/CreationEngine.cpp"

/**
 * @brief Function for specific code segment testing, without changing main
 * @returns 1 if successful
 */
auto test() -> int {
    // cout << "currently no test code" << endl;

    CreationEngine ENGINE;
    ifstream file("Database/Test_Entity.txt");

    if (!file) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Entity *test = ENGINE.createEntity(file);

    test->entity_description.get("name");

    delete test;

    return 0;
}

auto main(int argc, char *argv[]) -> int {
    render::Renderer renderer;
    game::Game handler(renderer);
    
    if(test() != 0) cerr << "Error while testing" << endl;

    return 0;
}
