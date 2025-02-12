#include "Entity.hpp"

// Get functions

auto Entity::get(const string& key) {
    return entity_attributes[key];
}

unordered_map<string, any> Entity::getMap() {
    return entity_attributes;
}

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

Attribute Entity::getAttribute(const size_t i) {
    return attributes[i];
}

vector<Attribute> Entity::listAttributes() {
    return attributes;
}

Attack Entity::getAttack(size_t i) {
    return Attacks_and_Spells[i];
}

vector<Attack> Entity::listAttacksAndSpells() {
    return Attacks_and_Spells;
}

// Set functions

void Entity::setAttr(const string& key, const any &value) {
    entity_attributes[key] = value;
}

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

Entity::Entity(unordered_map<string, any> map) {
    for (auto element : map) {
        entity_attributes[element.first] = element.second;
    }
}


void Entity::damage(int damage) {
    // get temporary and current hitpoints
    int temp_hp = any_cast<int>(get("temp_hp"));
    int current_hp = any_cast<int>(get("current_hp"));
    // account for temporary hitpoints
    if (temp_hp > 0) {
        setAttr("temp_hp", temp_hp - damage);
    }
    // rebalance hitpoints
    if (temp_hp < 0) {
        setAttr("current_hp", current_hp + temp_hp);
        setAttr("temp_hp", 0);
    }
}

void Entity::attack(Entity target) {
    // roll a d20 to hit
    if (rand() % 20 < any_cast<int>(target.get("armor_class"))) {
        std::cout << "Attack did not hit!" << endl;
        return;
    }
    std::cout << "Hit for ";
    
    // get an Attack from this Entity's roster
    vector<Attack> attacks = Attacks_and_Spells;
    Attack rndAttack = attacks[rand() % attacks.size()];

    // damage the target by rolling a die in the range defined by the attack used
    pair damage_range = any_cast<pair<int, int>>(rndAttack.get("damage_range"));
    int damage = rand() % damage_range.second + damage_range.first;
    target.damage(damage);
    std::cout << damage << " hitpoints!" << endl;
}