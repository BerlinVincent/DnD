#ifndef MONSTER_H_
#define MONSTER_H_

#include "Entity.hpp"

class Monster : public Entity {
    float challenge;
    public:
        using Entity::Entity;
        Monster(float challenge, string name, string descriptor, Alignment alignment, int max_health, int experience, uint proficiency_bonus, vector<int> attributes, vector<bool> proficiencies)
            : Entity(name, descriptor, alignment, max_health, experience, proficiency_bonus, attributes, proficiencies) {
            this->challenge = challenge;
        }
};

#endif // MONSTER_H_