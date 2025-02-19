#ifndef CREATION_ENGINE_C_
#define CREATION_ENGINE_C_

#include "CreationEngine.hpp"
#include <fstream>
#include <regex>

auto CreationEngine::createEntity(ifstream &file) -> Entity& {
    if (!file) throw runtime_error("invalid file pointer");
    if (!file.is_open()) throw runtime_error("error opening file");

    // create an Entity for reference 
    static Entity entity;
    // create a line for reference
    string line;

    // set a reference pattern "[...] : [...]"
    regex pattern(R"(\[(.+?)\] : \[(.+?)\])");
    smatch matches;

    size_t pair_count = 0;

    while (getline(file, line)) {
        // check line format
        if (!regex_match(line, matches, pattern)) {
            cerr << "invalid line format: " << line << endl;
            return entity;
        }

        // get key and value from line
        string key = matches[1].str();
        string value = matches[2].str();

        // insert first 3 pairs into description, the rest into statistics
        if (pair_count < 3) {
            entity.entity_description.set(key, value);
            pair_count++;
        } else {
            entity.entity_statistics.set(key, stoi(value));
        }        
    }

    return entity;
}

#endif // CREATION_ENGINE_C_