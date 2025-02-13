#ifndef CHARACTER_CLASS_H_
#define CHARACTER_CLASS_H_

#include "../inclusions.hpp"
#include "Skill.hpp"

enum Character_Classes {
    Barbarian,  Bard,       Cleric,
    Druid,      Fighter,    Monk,
    Paladin,    Ranger,     Rogue,
    Sorcerer,   Warlock,    Wizard
};

vector<string> char_class_names = {
    "Barbarian","Bard",     "Cleric",
    "Druid",    "Fighter",  "Monk",
    "Paladin",  "Ranger",   "Rogue",
    "Sorcerer", "Warlock",  "Wizard"
};

vector<string> primary_abilities = {
    "STR",          "CHA",          "WIS",
    "WIS",          "STR or DEX",   "DEX and WIS",
    "STR and CHA",  "DEX and WIS",  "DEX",
    "CHA",          "CHA",          "INT"
};

/* vector<Dice> hp_die = {
    "D12",  "D8",   "D8",
    "D8",   "D10",  "D8",
    "D10",  "D10",  "D8",
    "D6",   "D8",   "D6"
}; */

vector<vector<Skills>> st_proficiencies = {
    {STR_st, CON_st}, {DEX_st, CHA_st}, {WIS_st, CHA_st},
    {INT_st, WIS_st}, {STR_st, CON_st}, {STR_st, DEX_st},
    {WIS_st, CHA_st}, {DEX_st, WIS_st}, {DEX_st, INT_st},
    {CON_st, CHA_st}, {WIS_st, CHA_st}, {INT_st, WIS_st}
};

struct Character_Class {
    string name;
    vector<Attribute> primary_ability;
    // Dice hitpoint_die;
    vector<bool> st_prof;
    vector<bool> skill_prof;
    vector<bool> weapon_prof;
    vector<bool> armor_prof;
    vector<string> start_gear;
};

#endif // CHARACTER_CLASS_H_