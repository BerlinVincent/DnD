#ifndef MAIN_MENU_H_
#define MAIN_MENU_H_

#include <sstream>

namespace menu {

    inline const char* main_menu_data = R"(
        MenuName: Main Menu
    
        Option: Start Game
        Command: start_game
        ---
        Option: Create Character
        Command: start_character_creation
        ---
        Option: Quit Game
        Command: quit_game
        ---
    )";
    
    inline std::istringstream getMainMenuData() {
        return std::istringstream(main_menu_data);
    }

} //namespace menu

#endif // MAIN_MENU_H_