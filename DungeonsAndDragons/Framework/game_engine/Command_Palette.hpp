#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "Scenes.hpp"
#include "../CharacterCreator/CreationEngine.hpp"
#include <ncurses.h>
#include <functional>

using basicCommand = std::function<void()>;

static inline unordered_map<string, basicCommand> command_map = {
    {
        "start_game", []() {
            
        } 
    },
    {
        "start_character_creation", []() {
            clear();
            CreationEngine Create;
            Create.createPlayerFile();
        }
    },
    {
        "quit_game", []() {
            cout << endl;
            exit(0);
        }
    },
    {
        "open_sheet", []() {

        }
    }
};

#endif // COMMANDS_H_
