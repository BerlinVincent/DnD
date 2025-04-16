#include <iostream>
#include "Framework/game_engine/Game.hpp"
#include "Framework/CharacterCreator/CreationEngine.hpp"

namespace fs = std::filesystem;

/**
 * @brief Function for specific code segment testing, without changing main
 * @returns 1 if successful
 */
/*
auto test() -> int {
    // cout << "currently no test code" << endl;

    CreationEngine ENGINE;
    fs::path currentPath = fs::current_path();
    fs::path targetPath = "DungeonsAndDragons";

    cout << "Current working directory: " << currentPath << endl;

    while (currentPath.has_parent_path() && currentPath.filename() != "DnD") {
        currentPath = currentPath.parent_path();
    }

    if (currentPath.filename() == "DnD") {
        currentPath /= targetPath;
        cout << "Updated working directory: " << currentPath << endl;
    } else {
        cerr << "'DnD' directory not found" << endl;
        return 1;
    }

    fs::path testPath = currentPath / "Database/Test_Entity.txt";

    ifstream file(testPath);

    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    cout << "File opened successfully: " << testPath << endl;

    Entity *test = ENGINE.createEntity(file);

    cout << test->entity_description.get("name") << endl;

    delete test;
    file.close();

    return 0;
}

*/

auto main(int argc, char *argv[]) -> int {

    /*
    ifstream FileMainMenu("./Database/SheetFiles/MainMenu.txt", ios::in);
    scenes::Sheet SheetMainMenu(FileMainMenu);
    scenes::Scene scene(SheetMainMenu);
    render::Renderer renderer;
    game::Game handler(renderer, scene);
    */

    cout << "Getting FilePath" << endl;
    ifstream FileMainMenu("./Database/SheetFiles/MainMenu.txt");
    cout << "FilePath Got: " << endl << "Instantiating Sheet" << endl;
    scenes::Sheet SheetMainMenu(FileMainMenu);
    cout << "Sheet Instantiated" << endl << "Running Menu" << endl;
    SheetMainMenu.runMenu();
    cout << "Menu Run" << endl << "End of Sequence" << endl;
    
    //if(test() != 0) cerr << "Error while testing" << endl;

    return 0;
}
