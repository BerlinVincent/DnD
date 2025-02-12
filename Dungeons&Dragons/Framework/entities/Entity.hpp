#ifndef ENTITY_H_
#define ENTITY_H_

#include <utility>
#include <unordered_map>
#include "../statistics/Attacks_and_Spells.hpp"
#include "../statistics/Alignment.hpp"
#include "../statistics/Skill.hpp"

/**
* @brief A class for Entities in the game
* @details Entities are all kinds of NPCs and PCs. Thus they need to do A LOT : support character statistics and actions, integrate with the game engine and renderer and work with many different parts of the framework.
* @authors BerlinVincent
*/
class Entity {
    // Attributes of the Entity
    unordered_map<string, any> entity_attributes;

    /* All of this is now supposed to be folded into the entity_attributes map
    string name;
    string descriptor;
    Alignment alignment;
    // Active Entity Game Attributes
    int max_hp;
    int current_hp;
    int temp_hp;
    // AC, Initiative, Speed, Passive Wisdom
    int armor_class;
    int initiative;
    int speed;
    int passive_wisdom;
    // Proficiency Bonus, Hit Dice, Experience, Level
    int proficiency_bonus;
    int hit_dice;
    int experience;
    int level;
    */

    // Entity Game Attributes
    vector<Attribute> attributes;

    // Entity Saving Throws
    vector<Skill> saving_throws;

    // Entity Abilities, Traits, Feats
    vector<Attack> Attacks_and_Spells;
    vector<int> Traits_and_Feats;

    public:

        // Get functions

        /**
         * @brief A get function to get a class attribute from the entity_attributes Hashmap
         * @param key The string identifier of the attribute
         * @author BerlinVincent
         */
        auto get(string key);
        unordered_map<string, any> getMap();

        /* old get functions
        string getName();
        string getDesc();
        Alignment getAlign();
        vector<int> getHP();
        int getAC();
        int getInitiative();
        int getSpeed();
        int getPWis();
        int getProfBonus();
        int getHitDice();
        int getXP();
        int getLVL();
        */

        Attribute getAttribute(size_t i);
        vector<Attribute> listAttributes();
        Attack getAttack(size_t i);
        vector<Attack> listAttacksandSpells();

        // Set functions

        void setAttr(string key, any value);

        /* old set functions
        void rename(string newname);
        void redescribe(string newdesc);
        void realign(Alignment newalign);
        */

        /**
         * @brief A function to apply damage to an Entity
         * @param damage The amount of damage to be applied
         * @author BerlinVincent
         */
        void damage(int damage);
        
        // Constructors

        Entity() = default;
        Entity(unordered_map<string, int>);

        // Actions (currently mostly placeholders)

        /**
         * @brief A function to attack a target Entity.
         * (Would currently only work for single targeting)
         * @param target Attack's Entity target
         * @author BerlinVincent
         */
        void attack(Entity target);
        void spellcast(Entity target);
        void dash();
        void disengage();
        void dodge();
        void help(Entity target);
        void hide();
        void ready();
        void search();
        void useobject();
};

#endif // ENTITY_H_