#ifndef ENTITY_H_
#define EINTIY_H_

#include <utility>
#include "../Attacks_and_Spells.hpp"
#include "../Alignment.hpp"
#include "../Skill.hpp"

/**
* @brief A class for Entities in the game
* @details Entities are all kinds of NPCs and PCs. Thus they need to do A LOT: support character statistics and actions, integrate with the game engine and renderer and work with many different parts of the framework.
* @authors BerlinVincent
*/
class Entity {
    // Attributes
    // Entity Description
    string name;
    string descriptor;
    Alignment alignment;    

    // Active Entity Game Attributes
    // Health
    int max_health;
    int current_health;
    int temp_health;
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
        vector<Attribute> getAttributes() {return attributes;}
        
        // Constructors
        Entity() = default;
        Entity(string name, string descriptor, Alignment alignment, int max_health, int experience, uint proficiency_bonus, vector<int> attributes, vector<bool> proficiencies) {
            this->name = name;
            this->descriptor = descriptor;
            this->alignment = alignment;

            this->max_health = max_health;
            this->current_health = max_health;
            this->temp_health = 0;

            this->experience = experience;

            this->proficiency_bonus = proficiency_bonus;

            // I do not like how repetitive it looks; use for loop somehow?
            this->attributes = {
                Attribute("STR", attributes.at(STR)),
                Attribute("DEX", attributes.at(DEX)),
                Attribute("CON", attributes.at(CON)),
                Attribute("INT", attributes.at(INT)),
                Attribute("WIS", attributes.at(WIS)),
                Attribute("CHA", attributes.at(CHA)),
            };

            // Also repetitive
            saving_throws = {
                Skill("STR_st", this->attributes.at(STR), proficiencies.at(STR_st)),
                Skill("DEX_st", this->attributes.at(DEX), proficiencies.at(DEX_st)),
                Skill("CON_st", this->attributes.at(CON), proficiencies.at(CON_st)),
                Skill("INT_st", this->attributes.at(INT), proficiencies.at(INT_st)),
                Skill("WIS_st", this->attributes.at(WIS), proficiencies.at(WIS_st)),
                Skill("CHA_st", this->attributes.at(CHA), proficiencies.at(CHA_st)),
            };
        }
};

#endif // ENTITY_H_