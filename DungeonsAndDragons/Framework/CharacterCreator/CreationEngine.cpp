#ifndef CREATION_ENGINE_C_
#define CREATION_ENGINE_C_

#include "CreationEngine.hpp"
#include <fstream>
#include <regex>

auto CreationEngine::createEntity(ifstream &file) -> Entity * {
    if (!file) throw runtime_error("invalid file pointer");
    if (!file.is_open()) throw runtime_error("error opening file");
    
    // create a line for reference
    string line;
    // create two maps and an Attribute vector for Entity constructor call
    I_map<string> description_I_map;
    I_map<int> statistics_I_map;
    vector<Attribute> attributes;

    // set a reference pattern "[...] : [...]"
    regex pattern(R"(\[(.+?)\] : \[(.+?)\])");
    smatch matches;

    size_t block = 0;

    while (getline(file, line)) {
        // check for switch line
        if (line.empty()) {
            block++;
        }

        // check line format
        if (!regex_match(line, matches, pattern)) {
            cerr << "invalid line format: " << line << endl;
            exit(1);
        }

        // get key and value from line
        string key = matches[1].str();
        string value = matches[2].str();

        // insert first 2 pairs into description, the next into statistics, then into Attributes
        if (block == 0) {
            description_I_map.set(key, value);
        } else if (block == 1) {
            statistics_I_map.set(key, stoi(value));
        } else if (block == 2) {
            Attribute temp = Attribute(key, stoi(value));
            attributes.push_back(temp);
        }
    }

    Entity *entity = new Entity(description_I_map, statistics_I_map, attributes);

    return entity;
}

#endif // CREATION_ENGINE_C_