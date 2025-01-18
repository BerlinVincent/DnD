#include "inclusions.hpp"

enum Attributes {
    STR,
    DEX,
    CON,
    INT,
    WIS,
    CHA
};

vector<string> skill_names = {
    "acrobatics",
    "animal_handling",
    "arcana",
    "athletics",
    "deception",
    "history",
    "insight",
    "intimidation",
    "investigation",
    "medicine",
    "nature",
    "perception",
    "performance",
    "persuasion",
    "religion",
    "sleight_of_hand",
    "stealth",
    "survival"
};

enum Skills {
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

int calculate_modifier(int attribute) {
    return (attribute - 10) / 2;
}

int getParentAttribute(string skill) {
    
}

class Skill {
    string name;
    int modifier;
    bool proficiency;

    Skill(string name, int attribute, bool proficiency) {
        name = name;

        modifier = calculate_modifier(attribute);
        if (proficiency) modifier += 2;

        proficiency = proficiency;
    }
};