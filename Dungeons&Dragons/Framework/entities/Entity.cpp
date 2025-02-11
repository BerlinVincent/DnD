#include "Entity.hpp"

// Get functions

auto Entity::getAttr(string attr_name) {
    return class_attributes[attr_name];
}

auto Entity::getAttrMap() {
    return class_attributes;
}

string Entity::getName() {
    return name;
}

string Entity::getDesc() {
    return descriptor;
}

Alignment Entity::getAlign() {
    return alignment;
}

/* 
vector<int> Entity::getHP() {
    return {max_hp, current_hp, temp_hp};
}

int Entity::getAC() {
    return armor_class;
}
 */

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

void Entity::setAttr(string identifier, int value) {
    class_attributes[identifier] = value;
}

void Entity::rename(string newname) {
    this->name = newname;
}

void Entity::redescribe(string newdesc) {
    this->descriptor = newdesc;
}

void Entity::realign(Alignment newalign) {
    this->alignment = newalign;
}

void Entity::damage(int damage) {
    // account for temporary hitpoints
    if (getAttr("temp_hp") > 0) {
        setAttr("temp_hp", getAttr("temp_hp") - damage);
    }
    // rebalance hitpoints
    if (getAttr("temp_hp") < 0) {
        setAttr("current_hp", getAttr("current_hp") + getAttr("temp_hp"));
        setAttr("temp_hp", 0);
    }
}

void Entity::attack(Entity target) {
    // roll a d20 to hit
    if (rand() % 20 < target.getAttr("armor_class")) {
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