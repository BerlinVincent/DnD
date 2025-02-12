#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.hpp"

namespace game {
    class Player : public Entity {
        bool inspiration;
        
        // Player Game Skills
        vector<Skill> skills;

        public:
            Player() = default;
    };
}


#endif // PLAYER_H_
