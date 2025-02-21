#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.hpp"
#include "../statistics/Character_Class.hpp"

class Player : public Entity {
    Character_Class player_class;
    vector<Skill> skills;
    vector<string> gear;

    public:
        auto getClass() -> string&;
        auto getGear() -> vector<string>&;

        Player() = default;
};

#endif // PLAYER_H_