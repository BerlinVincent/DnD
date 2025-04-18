#ifndef ATTACKS_AND_SPELLS_H_
#define ATTACKS_AND_SPELLS_H_

#include "../inclusions.hpp"
#include <any>

struct RANGE {
    int low;
    int high;
};

/**
* @brief An enum for the different Damage Types of Dungeons&Dragons
*/
enum DamageType {
    PIERCING,
    BLUDGEONING,
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

/** 
* @brief An enum for the different Targeting Types of Dungeons&Dragons
*/
enum TargetType {
    SINGLE,
    MULTI,
    LINE,
    CONE,
    CUBE,
    SPHERE,
    CYLINDER
};

/**
* @brief A class for Attacks and Spells
* @details While Weapon Attacks are rather simple, Spells can have very different effects. We probably need to implement an Effect class at some point.
* @author BerlinVincent
*/
class Attack {
    string name;
    int enchant_bonus;
    RANGE damage_range;
    DamageType type;
    TargetType AoE;
    int reach;
    int action_type;
    int spellslot;

    public:
        auto getName() -> string;
        auto getEnchantBonus() -> int;
        auto getDamageRange() -> RANGE;
        auto getType() -> DamageType;
        auto getTargetType() -> TargetType;
        auto getReach() -> int;
        auto getActionType() -> int;
        auto getSpellslot() -> int;
};

#endif // ATTACKS_AND_SPELLS_H_