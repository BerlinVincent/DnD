#ifndef SKILL_C_
#define SKILL_C_

#include "Skill.hpp"

auto Skill::getName() -> string {
    return name;
}

auto Skill::getPAttr() -> Attribute {
    return parent_attribute;
}

auto Skill::getMod() -> int {
    return skill_mod;
}

auto Skill::hasProf() -> bool {
    return proficiency;
}

#endif // SKILL_C_