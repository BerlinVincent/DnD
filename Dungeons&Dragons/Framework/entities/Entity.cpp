#include "Entity.hpp"

// Get functions

string Entity::getName() {
    return name;
}

string Entity::getDesc() {
    return descriptor;
}

Alignment Entity::getAlign() {
    return alignment;
}

vector<int> Entity::getHP() {
    return {max_hp, current_hp, temp_hp};
}

int Entity::getAC() {
    return armor_class;
}

Attribute Entity::getAttribute(size_t i) {
    return attributes[i];
}

vector<Attribute> Entity::listAttributes() {
    return attributes;
}

Attack Entity::getAttack(size_t i) {
    return Attacks_and_Spells[i];
}

vector<Attack> Entity::listAttacksandSpells() {
    return Attacks_and_Spells;
}

// Set functions

string Entity::rename(string newname) {
    this->name = newname;
}

string Entity::redescribe(string newdesc) {
    this->descriptor = newdesc;
}

Alignment Entity::realign(Alignment newalign) {
    this->alignment = newalign;
}

void Entity::damage(int damage) {
    // account for temporary hitpoints
    if (temp_hp > 0) {
        temp_hp -= damage;
    }
    // rebalance hitpoints
    if (temp_hp < 0) {
        current_hp += temp_hp;
        temp_hp -= temp_hp;
    }
}

void Entity::attack(Entity target) {
    // roll a d20 to hit
    if (rand() % 20 < target.armor_class) {
        std::cout << "Attack did not hit!" << endl;
        return;
    }
    std::cout << "Hit for ";
    
    // get an Attack from this Entity's roster
    Attack rndAttack = getAttack(rand() % (Attacks_and_Spells.size()));

    // damage the target by rolling a dice in the range defined by the attack used
    int damage = rand() % rndAttack.damage.high + rndAttack.damage.low;
    target.damage(damage);
    std::cout << damage << " hitpoints!" << endl;
}