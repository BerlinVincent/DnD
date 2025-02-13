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
    // string Class Attributes of the Entity
    I_map<string> entity_description;
    // int Class Attributes of the Entity
    I_map<int> entity_statistics;

    /* All of this is now supposed to be folded into the maps above
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
        vector<Attack> listAttacksAndSpells();

        // Set functions

        void addAttack(Attack attack);

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
};

#endif // ENTITY_H_