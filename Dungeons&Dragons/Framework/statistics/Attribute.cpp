#include "Attribute.hpp"

auto Attribute::getName() -> string {
    return name;
}

auto Attribute::getScore() -> int {
    return score;
}

auto Attribute::getMod() -> int {
    return attr_mod;
}

void Attribute::recalcMod() {
    attr_mod = calculate_modifier(score);
}

void Attribute::scoreImprove() {
    score += 1;
}

void Attribute::scoreDiminish() {
    if(getScore() >= 1) score -= 1;
}