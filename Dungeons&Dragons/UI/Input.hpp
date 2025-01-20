#ifndef INPUT_H_
#define INPUT_H_

#include <string>
#include <variant>

namespace ui {

    class UI;

    using InputValue = std::variant<int,std::string>;

    enum class InputType {
        TEXT,    // enter Names
        MENU,    // select Menu Item
        ACTION,  // choose game action (Attacks, ...)
        D4,D5,D6 // Throw dice
    };

    struct Input{
        const InputType type;
        const std::string description;

        Input(InputType type, std::string description)
            : type(type), description(std::move(description))
        {}

        bool ready = false;
        InputValue value;
    };

}

#endif // INPUT_H_
