#ifndef ACTION_H_
#define ACTION_H_

#include "../inclusions.hpp"
#include "../entities/Entity.cpp"

class Action {
public:
  // Actions (currently mostly placeholders)

  /**
  * @brief A function to attack a target Entity.
  * (Would currently only work for single targeting)
  * @param attacker The attacking Entity
  * @param target The attack's Entity target
  * @returns boolean whether the function executed correctly
  * @author BerlinVincent
  */
  auto attack(Entity &attacker, Entity &target) -> bool;
  auto spellcast(Entity target) -> auto;
  auto dash() -> bool;
  auto disengage() -> bool;
  auto dodge() -> bool;
  auto help(Entity target) -> bool;
  auto hide() -> bool;
  auto ready() -> bool;
  auto search() -> bool;
  auto useObject() -> bool;
};

#endif // ACTION_H_