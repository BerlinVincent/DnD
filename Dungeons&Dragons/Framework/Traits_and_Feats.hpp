#include "inclusions.hpp"

class Trait {
    string name;
    vector<int> effect;
};

class Feat {
    string name;
    vector<Trait> effects;
};