#include "Attribute.hpp"

auto calculate_modifier(int attribute) -> int {
    return (attribute - 10) / 2;
}

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
    score++;
    recalcMod();
}

void Attribute::scoreDiminish() {
    if(getScore() >= 1) score--;
    recalcMod();
}

Attribute::Attribute(string name, int score)
    : name(name), score(score) {
        recalcMod();
    }