#include "Attacks_and_Spells.hpp"
#include "Alignment.hpp"
#include "Traits_and_Feats.hpp"

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
    // Inspiration, Proficiency Bonus, Hit Dice
    bool inspiration;
    uint proficiency_bonus;
    int hit_dice;

    // Entity Game Attributes
    uint strength;
    uint dexterity;
    uint constitution;
    uint intelligence;
    uint wisdom;
    uint charisma;

    // Entity Saving Throws
    int strength_st;
    int dexterity_st;
    int constitution_st;
    int intelligence_st;
    int wisdom_st;
    int charisma_st;

    //Entity Game Skills
    int acrobatics;
    int animal_handling;
    int arcana;
    int athletics;
    int deception;
    int history;
    int insight;
    int intimidation;
    int investigation;
    int medicine;
    int nature;
    int perception;
    int performance;
    int persuasion;
    int religion;
    int sleight_of_hand;
    int stealth;
    int survival;

    // Entity Abilities, Traits, Feats
    vector<Attack> Attacks_and_Spells;
    vector<Trait> Traits;
    vector<Feat> Feats;

    // Constructors
    Entity();
    Entity(vector<string> name_desc, Alignment alignment, int max_health, vector<uint> attr_profbon) {
        name = name_desc.at(0);
        descriptor = name_desc.at(1);
        alignment = alignment;

        max_health = max_health;
        current_health = max_health;
        temp_health = 0;

        proficiency_bonus = attr_profbon.at(0);

        strength = attr_profbon.at(1);
        dexterity = attr_profbon.at(2);
        constitution = attr_profbon.at(3);
        intelligence = attr_profbon.at(4);
        wisdom = attr_profbon.at(5);
        charisma = attr_profbon.at(6);
    }
};

class Monster : public Entity {
    public:
        uint challenge;
};