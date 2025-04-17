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
    regex pattern_line(R"(\[(.+?)\]\s*:\s*\[(.+?)\])");
    regex pattern_skip("^\\s*$");
    smatch matches;

    size_t block = 0;

    while (getline(file, line)) {

        // check data line
        if (regex_match(line, matches, pattern_line)) {

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
        // check for skip line
        else if(regex_match(line, matches, pattern_skip)) {
            block++;
        } 
        // check for invalid line format
        else {
            cerr << "invalid line format: " << line << endl;
            exit(1);
        }
    }
    
    Entity *entity = new Entity(description_I_map, statistics_I_map, attributes);

    return entity;
}

void CreationEngine::createPlayerFile() {
    filesystem::path walking_path = filesystem::current_path();
    filesystem::path target_path = "";
    
    while (walking_path.has_parent_path() && walking_path.filename() != "DnD") {
        walking_path = walking_path.parent_path();
        target_path /= "..";
    }
    target_path /= "DungeonsAndDragons/Database/Player.txt";

    ofstream file(target_path, ios::trunc);
    string line;
    vector<string> inputs = {
        "name",
        "descriptor",
        "max_hp",
        "armor_class",
        "speed",
        "challenge",
        "STR",
        "DEX",
        "CON",
        "INT",
        "WIS",
        "CHA"
    };

    for (size_t i = 0; i < inputs.size(); i++) {
        cout << "Enter " << inputs[i] << ": " << endl;
        getline(cin, line);

        if (i == 2 || i == 6) file << endl;
        file << "[" << inputs[i] << "] : [" << line << "]" << endl; 
    }
}