#ifndef SKILL_H_
#define SKILL_H_

#include "inclusions.hpp"
#include "Attribute.hpp"

/**
* @brief An enum for the Skills and Saving Throws of Dungeons&Dragons
* @details Saving Throws are included here, since they work very much like Skills.
*/
enum Skills {
    STR_st,
    DEX_st,
    CON_st,
    INT_st,
    WIS_st,
    CHA_st,
    acrobatics,
    animal_handling,
    arcana,
    athletics,
    deception,
    history,
    insight,
    intimidation,
    investigation,
    medicine,
    nature,
    perception,
    performance,
    persuasion,
    religion,
    sleight_of_hand,
    stealth,
    survival
};

/**
 * @brief A class implementing the Skills and Saving Throws a character can have in Dungeons&Dragons.
 * @details Like the Skill enum, Saving Throws are included due to the similarity to Skills.
 * @authors BerlinVincent
 */
class Skill {
    string name;
    Attribute parent_attribute;
    int skill_mod;
    bool proficiency;

    public:
        string getName() {return name;}
        Attribute getPAttr() {return parent_attribute;}
        int getMod() {return skill_mod;}
        bool hasProf() {return proficiency;};

        Skill() = default;
        Skill(string name, Attribute attribute, bool proficiency) {
            this->name = name;

            this->parent_attribute = attribute;
            this->proficiency = proficiency;

            this->skill_mod = parent_attribute.getMod();
            if (proficiency) skill_mod += 2;
        };
};

#endif // SKILL_H_