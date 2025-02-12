#include <iostream>
#include "./Framework/entities/Entity.cpp"

/**
 * @brief Function for specific code segment testing, without changing main
 * @returns 1 if successful
 */
int test() {
    Attack punch = Attack();
    pair<int, int> punch_range = {1, 3};
    punch.set("name", "punch");
    punch.set("attack_bonus", 0);
    punch.set("damage", punch_range);
    punch.set("type", BLUDGEONING);

    unordered_map<string, any> data;
    data["max_hp"] = 10;
    data["current_hp"] = 10;
    data["temp_hp"] = 0;
    data["armor_class"] = 3;

    Entity testE1 = Entity(data);
    Entity testE2 = Entity(data);

    testE1.addAttack(punch);

    cout << "---------------\n" << "Test Entity 1:" << endl;
    unordered_map<string, any> map = testE1.getMap();
    for(auto [first, second] : map) {
        cout << first << " " << any_cast<int>(second) << endl;
    }
    cout << "---------------\n" << "Test Entity 2:" << endl;
    map = testE2.getMap();
    for(auto [first, second] : map) {
        cout << first << " " << any_cast<int>(second) << endl;
    }
    cout << "---------------" << endl;

    testE1.attack(testE2);

    cout << "---------------\n" << "Test Entity 1:" << endl;
    map = testE1.getMap();
    for(auto [first, second] : map) {
        cout << first << " " << any_cast<int>(second) << endl;
    }
    cout << "---------------\n" << "Test Entity 2:" << endl;
    map = testE2.getMap();
    for(auto [first, second] : map) {
        cout << first << " " << any_cast<int>(second) << endl;
    }
    cout << "---------------" << endl;

    return 0;
}

auto main(int argc, char *argv[]) -> int {
    test();

    return 0;
}
