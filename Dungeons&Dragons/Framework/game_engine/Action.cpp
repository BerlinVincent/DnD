#include "Action.hpp"

bool Action::attack(Entity &attacker, Entity &target) {    
    // roll a d20 to hit;
    if (rand() % 20 < target.get("armor_class")) {
        cout << "Attack did not hit!" << endl;
        return true;
    }
    cout << "Hit for ";

    // get an Attack from the attacker's Attacks
    vector<Attack> attacks = attacker.listAttacksAndSpells();
    Attack rndAttack = attacks[rand() % attacks.size()];

    // calculate and apply damage from the Attack to the target
    auto damage_range = any_cast<pair<int, int>>(rndAttack.get("damage_range"));
    int damage = rand() % damage_range.second + damage_range.first;
    target.damage(damage);
    cout << damage << " hitpoints!" << endl;

    return true;
}