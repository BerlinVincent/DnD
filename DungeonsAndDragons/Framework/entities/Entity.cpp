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

Entity::Entity(I_map<string> descriptors, I_map<int> statistics, vector<Attribute> attributes) {
    entity_description = descriptors;
    entity_statistics = statistics;
    this->attributes = attributes;
    
    // set descriptors, if not given
    entity_description.set("name", descriptors.getMap().count("name") ? descriptors.get("name") : "Commoner");
    entity_description.set("descriptor", descriptors.getMap().count("name") ? descriptors.get("descriptor") : "Medium Humanoid");

    // set alignment, if not given
    entity_statistics.set("alignment", statistics.getMap().count("alignment") ? statistics.get("alignment") : TRUENEUTRAL);
    // set max_hp if not given and adjust current and temporary hitpoints
    int max_hp = statistics.getMap().count("max_hp") ? statistics.get("max_hp") : 4;
    entity_statistics.set("max_hp", max_hp);
    entity_statistics.set("current_hp", max_hp);
    entity_statistics.set("temp_hp", 0);
    // AC, Initiative, Speed, Passive Wisdom, Proficiency Bonus, Hit Dice, Experience, Level
    entity_statistics.set("armor_class", statistics.getMap().count("armor_class") ? statistics.get("armor_class") : 10);
    entity_statistics.set("speed", statistics.getMap().count("speed") ? statistics.get("speed") : 30);
    entity_statistics.set("passive_wisdom", statistics.getMap().count("passive_wisdom") ? statistics.get("passive_wisdom") : 10);
    entity_statistics.set("proficiency_bonus", statistics.getMap().count("proficiency_bonus") ? statistics.get("proficiency_bonus") : 2);
    entity_statistics.set("hit_dice", statistics.getMap().count("hit_dice") ? statistics.get("hit_dice") : 8);
    entity_statistics.set("experience", statistics.getMap().count("experience") ? statistics.get("experience") : 0);
    entity_statistics.set("level", statistics.getMap().count("level") ? statistics.get("level") : 1);
    entity_statistics.set("challenge", statistics.getMap().count("challenge") ? statistics.get("challenge") : 0);
}