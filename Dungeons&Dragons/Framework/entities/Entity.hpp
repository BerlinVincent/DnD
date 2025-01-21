#ifndef ENTITY_H_
#define EINTIY_H_

#include <utility>
#include "../statistics/Attacks_and_Spells.hpp"
#include "../statistics/Alignment.hpp"
#include "../statistics/Skill.hpp"

/**
* @brief A class for Entities in the game
* @details Entities are all kinds of NPCs and PCs. Thus they need to do A LOT: support character statistics and actions, integrate with the game engine and renderer and work with many different parts of the framework.
* @authors BerlinVincent
*/
class Entity {
    // Attributes
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
    uint proficiency_bonus;
    int hit_dice;
    int experience;
    int level;

    // Entity Game Attributes
    vector<Attribute> attributes;

    // Entity Saving Throws
    vector<Skill> saving_throws;

    // Entity Abilities, Traits, Feats
    vector<Attack> Attacks_and_Spells;
    vector<int> Traits_and_Feats;

    public:
        string getName() {return name;}
        string getDesc() {return descriptor;}
        Alignment getAlign() {return alignment;}

        vector<Attribute> getAttributes() {return attributes;}
        
        // Constructors
        Entity() = default;
        Entity(string name, string descriptor, Alignment alignment, int max_hp, int experience, uint proficiency_bonus, vector<int> attributes, vector<bool> proficiencies) {
            this->name = name;
            this->descriptor = descriptor;
            this->alignment = alignment;

            this->max_hp = max_hp;
            this->current_hp = max_hp;
            this->temp_hp = 0;

            this->experience = experience;

            this->proficiency_bonus = proficiency_bonus;

            vector<string> temp = {"STR", "DEX", "CON", "INT", "WIS", "CHA"};
            for (int i = 0; i < temp.size(); i++) {
                this->attributes[i] = Attribute(temp[i], attributes.at(i));
            }

            temp = {"STR_st", "DEX_st", "CON_st", "INT_st", "WIS_st", "CHA_st"};
            for (int i = 0; i < temp.size(); i++) {
                this->saving_throws[i] = Skill(temp[i], this->attributes[i], proficiencies[i]);
            }
        }
};

#endif // ENTITY_H_