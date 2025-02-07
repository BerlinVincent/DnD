#ifndef ENTITY_H_
#define EINTIY_H_

#include <utility>
#include "../statistics/Attacks_and_Spells.hpp"
#include "../statistics/Alignment.hpp"
#include "../statistics/Skill.hpp"

/**
* @brief A class for Entities in the game
* @details Entities are all kinds of NPCs and PCs. Thus they need to do A LOT: support character statistics and actions, integrate with the game engine and renderer and work with many different parts of the framework.
* @authors BerlinVincent
*/
class Entity {
    // Attributes
    string name;
    string descriptor;
    Alignment alignment;

    // Active Entity Game Attributes
    int max_hp;
    int current_hp;
    int temp_hp;
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

        // Get functions

        string getName() {return name;}
        string getDesc() {return descriptor;}
        Alignment getAlign() {return alignment;}
        vector<Attribute> getAttributes() {return attributes;}
        
        // Constructors

        Entity() = default;

        // Actions (currently placeholders)

        void attack(Entity target);
        void spellcast(Entity target);
        void dash();
        void disengage();
        void dodge();
        void help(Entity target);
        void hide();
        void ready();
        void search();
        void useobject();
};

#endif // ENTITY_H_