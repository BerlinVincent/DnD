#ifndef SKILL_H_
#define SKILL_H_

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

/** Right now a feature for later. 
 * @brief A class implementing the Skills and Saving Throws a character can have in Dungeons&Dragons.
 * @details Like the Skill enum, Saving Throws are included due to the similarity to Skills.
 * @authors BerlinVincent
 */
class Skill {
    string name;
    Attribute &parent_attribute;
    int skill_mod;
    bool proficiency;

    public:
        auto getName() -> string;
        auto getPAttr() -> Attribute &;
        auto getMod() -> int;
        auto hasProf() -> bool;

        void recalcMod();

        Skill(string name, Attribute &attribute, bool proficiency);
};

#endif // SKILL_H_