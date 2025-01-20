#ifndef CHARACTER_CLASS_H_
#define CHARACTER_CLASS_H_

#include "../inclusions.hpp"
#include "../Statistics Classes/Skill.hpp"

enum Character_Classes {
    Barbarian,
    Bard,
    Cleric,
    Druid,
    Fighter,
    Monk,
    Paladin,
    Ranger,
    Rogue,
    Sorcerer,
    Warlock,
    Wizard
};

class Character_Class {
    string name;
    Attribute primary_ability;
    // Dice hitpoint_die;
    vector<bool> st_proficiencies;
    vector<bool> skill_proficiencies;
};

#endif // CHARACTER_CLASS_H_