#ifndef ACTION_H_
#define ACTION_H_

#include "../inclusions.hpp"
#include "../entities/Entity.cpp"

class Action {
    // Actions (currently mostly placeholders)

    /**
     * @brief A function to attack a target Entity.
     * (Would currently only work for single targeting)
     * @param attacker The attacking Entity
     * @param target The attack's Entity target
     * @returns boolean whether the function executed correctly
     * @author BerlinVincent
     */
    bool attack(Entity &attacker, Entity &target);
    bool spellcast(Entity target);
    bool dash();
    bool disengage();
    bool dodge();
    bool help(Entity target);
    bool hide();
    bool ready();
    bool search();
    bool useObject();
};

#endif // ACTION_H_