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
    if (skill == skill_names.at(athletics)) {
        return STR;
    } else if (skill == skill_names.at(acrobatics) || skill == skill_names.at(sleight_of_hand) || skill == skill_names.at(stealth)) {
        return DEX;
    } else if (skill == skill_names.at(arcana) || skill == skill_names.at(history) || skill == skill_names.at(investigation) || skill == skill_names.at(nature) || skill == skill_names.at(religion)) {
        return INT;
    } else if (skill == skill_names.at(animal_handling) || skill == skill_names.at(insight) || skill == skill_names.at(medicine) || skill == skill_names.at(perception) || skill == skill_names.at(survival)) {
        return WIS;
    } else if (skill == skill_names.at(deception) || skill == skill_names.at(intimidation) || skill == skill_names.at(performance) || skill == skill_names.at(persuasion)) {
        return CHA;
    } else return -1;
}

class Skill {
    string name;
    int modifier;
    bool proficiency;

    public:
        Skill(string name, int attribute, bool proficiency) {
            name = name;

            modifier = calculate_modifier(attribute);
            if (proficiency) modifier += 2;

            proficiency = proficiency;
        }
};