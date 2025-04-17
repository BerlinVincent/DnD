#include <iostream>
#include "Framework/game_engine/Game.hpp"
#include "Framework/CharacterCreator/CreationEngine.hpp"

namespace fs = std::filesystem;

void ncursesInit() {
    initscr();
    noecho();
    curs_set(TRUE);
    keypad(stdscr, true);
}

auto main(int argc, char *argv[]) -> int {

    ifstream FileMainMenu("../../DungeonsAndDragons/Database/SheetFiles/MainMenu.txt");
    if (!FileMainMenu.is_open()) {
        cout << "File not opened" << endl;
        return 1;
    }
    scenes::Sheet SheetMainMenu(FileMainMenu);

    /* This does not work yet
    render::Renderer renderer;
    game::Game handler(renderer, SheetMainMenu);
    */

    ncursesInit();
    SheetMainMenu.runMenu();

    return 0;
}
