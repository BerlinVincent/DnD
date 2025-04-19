#include <iostream>
#include "Framework/game_engine/Game.hpp"
#include "Framework/CharacterCreator/CreationEngine.hpp"
#include "Database/SheetFiles/menu_inclusions.hpp"

namespace fs = std::filesystem;

void ncursesInit() {
    initscr();
    noecho();
    curs_set(TRUE);
    keypad(stdscr, true);
}

auto main(int argc, char *argv[]) -> int {
    
    istringstream StreamMainMenu = menu::getMenuStream("main");
    scenes::Sheet SheetMainMenu(StreamMainMenu);

    /* This does not work yet
    render::Renderer renderer;
    game::Game handler(renderer, SheetMainMenu);
    */

    ncursesInit();
    SheetMainMenu.runMenu();

    return 0;
}
