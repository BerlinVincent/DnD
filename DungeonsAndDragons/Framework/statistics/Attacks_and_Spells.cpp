#include "Attacks_and_Spells.hpp"

auto Attack::getName() -> string {
    return name;
}

auto Attack::getAtkBonus() -> int {
    return attack_bonus;
}

auto Attack::getDamageRange() -> RANGE {
    return damage_range;
}

auto Attack::getType() -> DamageType {
    return type;
}

auto Attack::getTargetType() -> TargetType {
    return AoE;
}

auto Attack::getReach() -> int {
    return reach;
}

auto Attack::getActionType() -> int {
    return action_type;
}

auto Attack::getSpellslot() -> int {
    return spellslot;
}