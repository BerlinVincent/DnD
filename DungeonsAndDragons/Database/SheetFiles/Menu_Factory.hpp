#ifndef MENU_FACTORY_H_
#define MENU_FACTORY_H_

#include <memory>
#include <unordered_map>
#include <functional>

#include "menu_inclusions.hpp"
#include "../../Framework/game_engine/Scenes.hpp"

namespace menu {

    std::istringstream getMenuStream(string name);
    
} //namespace menu

#endif // MENU_FACTORY_H_