#ifndef SCENES_H_
#define SCENES_H_

#include <variant>
namespace scenes {
    struct Combat {
        // Pokémon-inspired Combat Screen
    };

    struct Explore {
        // 2D Room Map
    };

    struct Sheet {
        // Character Sheet, Inventory, Menus in general
    };

    /**
     * @brief A class for the different Game Scenes
     * @details The Game is divided into Scenes
     *          COMBAT    - Game is in Combat State
     *          EXPLORE   - Player is exploring Dungeon Room
     *          INVENTORY - Inventory View
     * @authors PeterfoxUwU, BerlinVincent
     */
    class Scene {
    public:

        std::variant<Combat, Explore, Sheet> currentScene;
    };
}  // namespace scenes

#endif  // SCENES_H_