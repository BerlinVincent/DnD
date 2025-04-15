#include "Action.hpp"

auto Action::attack(entity::Entity &attacker, entity::Entity &target) -> bool{    
    // roll a d20 to hit
    if (rand() % 20 < target.entity_statistics.get("armor_class")) {
        cout << "Attack did not hit!" << endl;
        return true;
    }
    cout << "Hit for ";

    // get an Attack from the attacker's Attacks
    vector<Attack> attacks = attacker.listAttacksAndSpells();
    Attack rndAttack = attacks[rand() % attacks.size()];

    // calculate and apply damage from the Attack to the target
    auto damage_range = rndAttack.getDamageRange();
    int damage = rand() % damage_range.high + damage_range.low;
    target.damage(damage);
    cout << damage << " hitpoints!" << endl;

    return true;
}