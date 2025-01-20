#ifndef UI_H_
#define UI_H_

#include "Input.hpp"
#include "../Framework/Player.hpp"
#include "../Framework/Scenes.hpp"

namespace ui {

    enum class MessageType{
    HINT, WARNING
    };

    /*
    ** User Interface
    ** used to render Game and recieve User input
    */
    class UI
    {
        /*
        ** Render and Display GameState to User
        */
        virtual auto render(const game::Player &player,
                            const scenes::Scene &) -> bool = 0;
        // /*
        // ** Create User input Request
        // ** TODO add Styleing options
        // */
        // virtual auto registerInput(Input &input) -> void = 0;

        /*
        ** Display Message to User
        ** ex. Hints or Warnings
        */
        virtual auto showMessage(MessageType type, std::string text) -> void = 0;
    };
}


#endif // UI_H_
