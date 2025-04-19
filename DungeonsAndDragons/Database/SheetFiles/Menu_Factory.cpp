#include "Menu_Factory.hpp"

namespace menu {

    using MenuFactory = std::function<std::istringstream()>;

    std::unordered_map<std::string, MenuFactory> menu_loaders = {
        {
            "main", getMainMenuData
        },
        //{
        //    "inventory", getInventoryData
        //}
    };
    
    std::istringstream getMenuStream(string name) {
        return menu_loaders.at(name)();
    }

} //namespace menu
