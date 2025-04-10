#ifndef SCENES_H_
#define SCENES_H_

#include "../entities/Player.hpp"
#include "Action.hpp"
#include <variant>
#include <vector>
#include <utility>

namespace scenes {
    /**
     * @brief Struct to hold Combat Information and Methods to modify any stats
     * @authors BerlinVincent
     */
    struct Combat {
    public:
        Combat(Player& player, Entity& enemy);

        void playerAttack();
        void enemyAttack();
    private:
        Action act;
        Player& player;
        Entity& enemy;
        int turn;
    };

    /**
     * @brief Struct to hold Room Information and Methods to modify the room
     * @authors BerlinVincent
     */
    struct Explore {
    public:
        Explore(int width, int height);

        void placeWall(int x, int y);
        void placeGround(int x, int y);
        void placePlayer(int x, int y);
        void placeEntity(int x, int y);
    private:
        std::vector<std::vector<char>> room_map;
        std::pair<int, int> player_pos;

        auto inBounds(int x, int y) -> bool;
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

        Scene(const Combat& combat) : currentScene(combat) {}
        Scene(const Explore& explore) : currentScene(explore) {}
        Scene(const Sheet& sheet) : currentScene(sheet) {}

        const std::variant<Combat, Explore, Sheet>& getVariant() const {
            return currentScene;
        }
    };
}  // namespace scenes

#endif  // SCENES_H_