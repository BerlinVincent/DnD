#include "inclusions.hpp"

/**
* @brief An enum for the different Damage Types of Dungeons&Dragons
*/
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
