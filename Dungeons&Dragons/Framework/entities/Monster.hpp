#ifndef MONSTER_H_
#define MONSTER_H_

#include "Entity.hpp"

class Monster : public Entity {
    float challenge;
    public:
        Monster() = default;
};

#endif // MONSTER_H_