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

    /* All of this is now supposed to be folded into the maps above
    string name;
    string descriptor;
    Alignment alignment;
    // Active Entity Game Attributes
    int max_hp;
    int current_hp;
    int temp_hp;
    // AC, Initiative, Speed, Passive Wisdom, Proficiency Bonus, Hit Dice, Experience, Level
    int armor_class;
    int speed;
    int passive_wisdom;
    int proficiency_bonus;
    int hit_dice;
    int experience;
    int level;
    int challenge
    */

    // Entity Game Attributes
    vector<Attribute> attributes;
    // Entity Saving Throws
    vector<Skill> saving_throws;
    // Entity Abilities, Traits, Feats
    vector<Attack> Attacks_and_Spells;
    vector<int> Traits_and_Feats;

    public:
    
        // string Class Attributes of the Entity
        I_map<string> entity_description;
        // int Class Attributes of the Entity
        I_map<int> entity_statistics;

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

        auto getAttribute(size_t i) -> Attribute;
        auto listAttributes() -> vector<Attribute>;
        auto getAttack(size_t i) -> Attack;
        auto listAttacksAndSpells() -> vector<Attack>;

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

        /**
         * @brief Entity Constructor, standard stats are that of a commoner
         * @link https://www.dndbeyond.com/monsters/16829-commoner
         * @param descriptors a name and description
         * @param statistics Entity statistics, like hitpoints, armor class, level, etc.
         * @param attributes Entity Attributes with given values
         * @authors BerlinVincent
         */
        Entity(
            I_map<string> descriptors,
            I_map<int> statistics,
            vector<Attribute> attributes
        );
};

#endif // ENTITY_H_