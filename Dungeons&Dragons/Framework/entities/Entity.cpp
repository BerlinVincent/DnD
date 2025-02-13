#include "Entity.hpp"

// Get functions
/* old get functions
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
*/

auto Entity::getAttribute(const size_t i) -> Attribute {
    return attributes[i];
}

auto Entity::listAttributes() -> vector<Attribute> {
    return attributes;
}

auto Entity::getAttack(size_t i) -> Attack {
    return Attacks_and_Spells[i];
}

auto Entity::listAttacksAndSpells() -> vector<Attack> {
    return Attacks_and_Spells;
}

// Set functions

void Entity::addAttack(Attack attack) {
    Attacks_and_Spells.insert(Attacks_and_Spells.end(), attack);
}

/* old set functions
void Entity::rename(string newname) {
    this->name = newname;
}

void Entity::redescribe(string newdesc) {
    this->descriptor = newdesc;
}

void Entity::realign(Alignment newalign) {
    this->alignment = newalign;
}
*/

void Entity::damage(int damage) {
    // get temporary and current hitpoints
    int temp_hp = entity_statistics.get("temp_hp");
    int current_hp = entity_statistics.get("current_hp");
    // account for temporary hitpoints
    if (temp_hp > 0) {
        entity_statistics.set("temp_hp", temp_hp - damage);
    }
    // rebalance hitpoints
    if (temp_hp < 0) {
        entity_statistics.set("current_hp", current_hp + temp_hp);
        entity_statistics.set("temp_hp", 0);
    }
}