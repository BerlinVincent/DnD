#include <iostream>
#include "Framework/game_engine/Game.hpp"
#include "Framework/CharacterCreator/CreationEngine.hpp"

namespace fs = std::filesystem;

void ncursesInit() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, true);
}

auto main(int argc, char *argv[]) -> int {
    
    /*
    render::Renderer renderer;
    game::Game handler(renderer, scene);
    */

    ifstream FileMainMenu("../../DungeonsAndDragons/Database/SheetFiles/MainMenu.txt");
    if (!FileMainMenu.is_open()) {
        cout << "File not opened" << endl;
        return 1;
    }
    scenes::Sheet SheetMainMenu(FileMainMenu);

    ncursesInit();
    SheetMainMenu.runMenu();

    return 0;
}
