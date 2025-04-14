#ifndef SCENES_H_
#define SCENES_H_

#include "../entities/Player.hpp"
#include "Action.hpp"
#include "Command_Palette.hpp"
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

        /**
         * @brief Constructor for Combat Scenes
         */
        Combat(Player& player, Entity& enemy) :
            player(player),
            enemy(enemy),
            act() {
            turn = 0;
        }

        /**
         * @brief Function for Attacks by the Player
         */
        void playerAttack();

        /**
         * @brief Function for Attacks by non-Players
         */
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
        
        /**
         * @brief Constructor for Room Explore Scenes
         */
        Explore(int width, int height);

        /**
         * @brief Function for placing objects in the room
         */
        void placeObj(int x, int y, char Obj);
        /**
         * @brief Function for moving the Player in the room
         */
        void move(int key);
    
    private:
        vector<std::vector<char>> room_map;
        pair<int, int> player_pos;

        /**
         * @brief Simple function for coordinate bounds checks
         */
        auto inBounds(int x, int y) -> bool;
    };

    struct MenuOption {
        string label;
        string command;
    };

    struct Sheet {
    public:

        /**
         * @brief Constructor for Sheet Scenes, e.g. Menus, Character Sheets, Inventories, etc.
         */
        Sheet(ifstream &file);

        /**
         * This belongs into the renderer, I think
         * @brief Function for displaying of Sheets
         */
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