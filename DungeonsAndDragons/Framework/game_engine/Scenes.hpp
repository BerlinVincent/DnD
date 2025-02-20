#ifndef SCENES_H_
#define SCENES_H_

#include <variant>
namespace scenes {

    /**
     * @brief A class for the different Game Scenes
     * @details The Game is divided into Scenes
     *          COMBAT    - Game is in Combat State
     *          EXPLORE   - Player is exploring Dungeon Room
     *          INVENTORY - Inventory View
     * @authors PeterfoxUwU
     */
    class Scene {
        struct Combat {
            // enemy Grid
            // background img
        };

        struct Explore {
            // 2D Room Map
        };

        struct Inventory {
            // items
        };

        std::variant<Combat, Explore, Inventory> scene;
    };
}  // namespace scenes

#endif  // SCENES_H_