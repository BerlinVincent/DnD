#include "Skill.hpp"

auto Skill::getName() -> string {
    return name;
}

auto Skill::getPAttr() -> Attribute & {
    return parent_attribute;
}

auto Skill::getMod() -> int {
    recalcMod();
    return skill_mod;
}

auto Skill::hasProf() -> bool {
    return proficiency;
}

void Skill::recalcMod() {
    skill_mod = parent_attribute.getMod();
    if (hasProf()) skill_mod += 2;
}

Skill::Skill(string name, Attribute &attribute, bool proficiency) 
    : name(name), parent_attribute(attribute), proficiency(proficiency) {
    skill_mod = parent_attribute.getMod();
    if (proficiency) skill_mod += 2;
};