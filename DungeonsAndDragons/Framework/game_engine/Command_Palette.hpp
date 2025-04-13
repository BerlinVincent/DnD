#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "Scenes.hpp"

using basicCommand = std::function<void()>;

unordered_map<string, basicCommand> command_map = {
    {
        "start_game", []() {
            
        } 
    },
    {
        "quit_game", []() {
            exit(0);
        }
    },
    {
        "open_sheet", []() {

        }
    }
};

#endif // COMMANDS_H_