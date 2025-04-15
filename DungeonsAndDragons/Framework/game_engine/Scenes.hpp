#ifndef SCENES_H_
#define SCENES_H_

#include "../entities/Player.hpp"
#include "Action.hpp"
// #include "Command_Palette.hpp"
#include <fstream>
#include <regex>
#include <variant>
#include <vector>
#include <utility>
#include <ncurses.h>

namespace scenes {
    /**
     * @brief Struct to hold Combat Information and Methods to modify any stats
     * @authors BerlinVincent
     */
    struct Combat {
    public:
        Combat(Player& player, Entity& enemy) :
            player(player),
            enemy(enemy),
            act() {
            turn = 0;
        }

        void playerAttack();
        void enemyAttack();
    private:
        Action act;
        Player &player;
        Entity &enemy;
        int turn;
    };

    /**
     * @brief Struct to hold Room Information and Methods to modify the room
     * @authors BerlinVincent
     */
    struct Explore {
    public:
        Explore(int width, int height);

        void placeObj(int x, int y, char Obj);
        void move(int key);
    private:
        vector<std::vector<char>> room_map;
        pair<int, int> player_pos;

        auto inBounds(int x, int y) -> bool;
    };

    struct MenuOption {
        string label;
        string command;
    };

    struct Sheet {
    public:
        Sheet(ifstream &file);

        void runMenu();
    private:
        string menuName;
        std::vector<MenuOption> options;
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
        variant<Combat, Explore, Sheet> currentScene;

        Scene(const Combat &combat) : currentScene(combat) {}
        Scene(const Explore &explore) : currentScene(explore) {}
        Scene(const Sheet &sheet) : currentScene(sheet) {}

        const variant<Combat, Explore, Sheet>& getVariant() const {
            return currentScene;
        }
    };
}  // namespace scenes

#endif  // SCENES_H_
