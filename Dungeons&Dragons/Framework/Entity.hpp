#include <utility>

#include "Attacks_and_Spells.hpp"
#include "Alignment.hpp"
#include "Attribute.hpp"
#include "Skill.hpp"

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
    // Inspiration, Proficiency Bonus, Hit Dice, Experience, Level
    bool inspiration;
    uint proficiency_bonus;
    int hit_dice;
    int experience;
    int level;

    // Entity Game Attributes
    vector<Attribute> attributes;

    // Entity Saving Throws
    vector<Skill> saving_throws;

    //Entity Game Skills
    vector<Skill> skills;

    // Entity Abilities, Traits, Feats
    vector<Attack> Attacks_and_Spells;
    vector<int> Traits_and_Feats;

    // Constructors
    Entity(string name, string descriptor, Alignment alignment, int max_health, int experience, uint proficiency_bonus, vector<int> new_attributes, vector<bool> proficiencies) {
        name = name;
        descriptor = descriptor;
        alignment = alignment;

        max_health = max_health;
        current_health = max_health;
        temp_health = 0;

        experience = experience;

        proficiency_bonus = proficiency_bonus;

        attributes = {
            Attribute("STR", new_attributes.at(STR)),
            Attribute("DEX", new_attributes.at(DEX)),
            Attribute("CON", new_attributes.at(CON)),
            Attribute("INT", new_attributes.at(INT)),
            Attribute("WIS", new_attributes.at(WIS)),
            Attribute("CHA", new_attributes.at(CHA)),
        };

        saving_throws = {
            Skill("STR_st", attributes.at(STR), proficiencies.at(STR_st)),
            Skill("DEX_st", attributes.at(DEX), proficiencies.at(DEX_st)),
            Skill("CON_st", attributes.at(CON), proficiencies.at(CON_st)),
            Skill("INT_st", attributes.at(INT), proficiencies.at(INT_st)),
            Skill("WIS_st", attributes.at(WIS), proficiencies.at(WIS_st)),
            Skill("CHA_st", attributes.at(CHA), proficiencies.at(CHA_st)),
        };

        skills = {
            Skill("acrobatics",         attributes.at(DEX), proficiencies.at(acrobatics)),
            Skill("animal_handling",    attributes.at(WIS), proficiencies.at(animal_handling)),
            Skill("arcana",             attributes.at(INT), proficiencies.at(arcana)),
            Skill("athletics",          attributes.at(STR), proficiencies.at(athletics)),
            Skill("deception",          attributes.at(CHA), proficiencies.at(deception)),
            Skill("history",            attributes.at(INT), proficiencies.at(history)),
            Skill("insight",            attributes.at(WIS), proficiencies.at(insight)),
            Skill("intimidation",       attributes.at(CHA), proficiencies.at(intimidation)),
            Skill("investigation",      attributes.at(INT), proficiencies.at(investigation)),
            Skill("medicine",           attributes.at(WIS), proficiencies.at(medicine)),
            Skill("nature",             attributes.at(INT), proficiencies.at(nature)),
            Skill("perception",         attributes.at(WIS), proficiencies.at(perception)),
            Skill("performance",        attributes.at(CHA), proficiencies.at(performance)),
            Skill("persuasion",         attributes.at(CHA), proficiencies.at(persuasion)),
            Skill("religion",           attributes.at(INT), proficiencies.at(religion)),
            Skill("sleight_of_hand",    attributes.at(DEX), proficiencies.at(sleight_of_hand)),
            Skill("stealth",            attributes.at(DEX), proficiencies.at(stealth)),
            Skill("survival",           attributes.at(WIS), proficiencies.at(survival))
        };
    }
    Entity();
};

// this belongs in its own .hpp file
class Monster : public Entity {
    public:
        uint challenge;
};
