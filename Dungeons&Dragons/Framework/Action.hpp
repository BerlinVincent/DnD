#ifndef ACTION_H_
#define ACTION_H_

#include <forward_list>
#include <functional>
#include <string>
#include "../UI/Input.hpp"
#include "../Framework/State.hpp"

using ActionExecutor = std::function<Action(game::State&, std::forward_list<ui::InputValue>)>;

enum class ActionExec {
Attack
};
/*
** Execute Action requireing user Interaction
** by evaluating
*/
struct Action : Pack, Unpack {

    std::forward_list<std::string> options;
    std::forward_list<ui::Input> inputs;


};

#endif // ACTION_H_
