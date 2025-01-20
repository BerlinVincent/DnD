#ifndef ATTACKS_AND_SPELLS_H_
#define ATTACKS_AND_SPELLS_H_

#include "inclusions.hpp"

enum DamageType {
    PIERCING,
    BLUDEONING,
    SLASHING,
    COLD,
    FIRE,
    LIGHTNING,
    THUNDER,
    POISON,
    ACID,
    NECROTIC,
    RADIANT,
    FORCE,
    PSYCHIC
};

enum TargetType {
    SINGLE,
    MULTI,
    LINE,
    CONE,
    CUBE,
    SPHERE,
    CYLINDER
};

class Attack {
    string name;
    int attack_bonus;
    int damage;
    DamageType type;
    TargetType AoE;
    int reach;
    int action_type;
    int spellslot;
};

#endif ATTACKS_AND_SPELL_H_