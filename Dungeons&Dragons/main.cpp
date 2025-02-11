#include <iostream>
#include "./Framework/entities/Entity.cpp"

/**
 * @brief Function for specific code segment testing, without changing main
 * @returns 1 if successful
 */
int test() {
    Entity testE1 = Entity();
    Entity testE2 = Entity();

    testE1.setAttr("max_hp", 10);
    testE1.setAttr("current_hp", 10);
    testE1.setAttr("temp_hp", 0);
    testE1.setAttr("armor_class", 10);

    cout << "---------------\n" << "Test Entity 1:" << endl;
    unordered_map<string, int> map = testE1.getAttrMap();
    for(auto elem : map) {
        cout << elem.first << " " << elem.second << endl;
    }

    testE2.setAttr("max_hp", 10);
    testE2.setAttr("current_hp", 10);
    testE2.setAttr("temp_hp", 0);
    testE2.setAttr("armor_class", 10);

    cout << "---------------\n" << "Test Entity 2:" << endl;
    map = testE2.getAttrMap();
    for(auto elem : map) {
        cout << elem.first << " " << elem.second << endl;
    }

    cout << "---------------" << endl;
    return 0;
}

auto main(int argc, char *argv[]) -> int {
    test();

    return 0;
}
