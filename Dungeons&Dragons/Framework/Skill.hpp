#include "inclusions.hpp"

int attr_mod(int attribute) {
        return (attribute - 10) / 2;
}

class Skill {
    string name;
    int modifier;
    bool proficiency;

    Skill(string name, int attribute, bool proficiency) {
        name = name;
        modifier = attr_mod(attribute);
        if (proficiency) modifier += 2;
        proficiency = proficiency;
    }
};