#include <iostream>
#include <fstream>
#include <filesystem>
#include "Framework/game_engine/Game.cpp"
#include "Framework/CharacterCreator/CreationEngine.cpp"

namespace fs = std::filesystem;

/**
 * @brief Function for specific code segment testing, without changing main
 * @returns 1 if successful
 */
auto test() -> int {
    // cout << "currently no test code" << endl;

    CreationEngine ENGINE;
    fs::path testpath{"./DungeonsAndDragons/Database/Test_Entity.txt"};

    cout << "Current working directory: " << fs::current_path() << endl;

    ifstream file(testpath);

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Entity *test = ENGINE.createEntity(file);

    cout << test->entity_description.get("name") << endl;

    delete test;
    file.close();

    return 0;
}

auto main(int argc, char *argv[]) -> int {
    render::Renderer renderer;
    game::Game handler(renderer);
    
    if(test() != 0) cerr << "Error while testing" << endl;

    return 0;
}
