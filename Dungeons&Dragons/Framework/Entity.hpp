#include "Attacks_and_Spells.hpp"
#include "Alignment.hpp"
#include "Skill.hpp"

enum Attributes {
    STR,
    DEX,
    CON,
    INT,
    WIS,
    CHA
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
    vector<uint> attributes;

    // Entity Saving Throws
    vector<int> saving_throws;

    //Entity Game Skills
    vector<Skill> skills;

    // Entity Abilities, Traits, Feats
    vector<Attack> Attacks_and_Spells;
    vector<int> Traits_and_Feats;

    // Constructors
    Entity(string name, string descriptor, Alignment alignment, int max_health, int experience, vector<uint> attributes, uint proficiency_bonus) {
        name = name;
        descriptor = descriptor;
        alignment = alignment;

        max_health = max_health;
        current_health = max_health;
        temp_health = 0;

        experience = experience;

        proficiency_bonus = proficiency_bonus;

        attributes = attributes;

        for (int i = 0; i < saving_throws.size(); i++) {
            saving_throws.at(i) = attr_mod(attributes.at(i));
        }
    }
    Entity();
};

class Monster : public Entity {
    public:
        uint challenge;
};