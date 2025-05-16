#include "CreationEngine.hpp"
#include <ncurses.h>
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

    cout << endl;

    for (size_t i = 0; i < inputs.size(); i++) {
        cout << "Enter " << inputs[i] << ": " << endl;
        getline(cin, line);

        if (i == 2 || i == 6) file << endl;
        file << "[" << inputs[i] << "] : [" << line << "]" << endl; 
    }
}

void CreationEngine::createPlayerFile2() {
    filesystem::path walking_path = filesystem::current_path();
    filesystem::path target_path = "";
    
    while (walking_path.has_parent_path() && walking_path.filename() != "DnD") {
        walking_path = walking_path.parent_path();
        target_path /= "..";
    }
    target_path /= "DungeonsAndDragons/Database/Player.txt";

    ofstream file(target_path, ios::trunc);
    string line;
    vector<pair<string, string>> prompts = {
        {"name", "-"},
        {"descriptor", "-"},
        {"max_hp", "0"},
        {"armor_class", "0"},
        {"speed", "0"},
        {"challenge", "0"},
        {"STR", "0"},
        {"DEX", "0"},
        {"CON", "0"},
        {"INT", "0"},
        {"WIS", "0"},
        {"CHA", "0"}
    };

    size_t highlight = 0;
    int input;
    char buffer[100];
    bool done = false;

    while(!done) {
        clear();
        mvaddstr(0, 0, "Character Creation Menu (↑/↓ zum Navigieren, Enter zum Bearbeiten)");

        for (size_t i = 0; i < prompts.size(); i++) {
            string prompt = prompts[i].first + " : ";
            mvaddstr(i + 2, 1, prompt.c_str());
            if (i == highlight) attron(A_REVERSE);
            mvaddstr(i + 2, 20, prompts[i].second.c_str());
            if (i == highlight) attroff(A_REVERSE);
        }

        size_t done_index = prompts.size();
        if (highlight == done_index) attron(A_REVERSE);
        mvaddstr(done_index + 3, 2, "Done");
        if (highlight == done_index) attroff(A_REVERSE);
        int temp;

        input = getch();

        switch (input) {
            case KEY_UP:
                highlight = (highlight == 0) ? prompts.size() : highlight - 1;
                break;
            case KEY_DOWN:
                highlight = (highlight == prompts.size()) ? 0 : highlight + 1;
                break;
            case KEY_LEFT:
                if ((highlight > 5 && highlight < 12)) {
                    try {
                        temp = std::stoi(prompts[highlight].second);
                        if (temp > 0) {
                            temp--;
                            prompts[highlight].second = std::to_string(temp);
                        }
                    } catch (const std::exception& e) {}
                }
                break;
            case KEY_RIGHT:
                if ((highlight > 5 && highlight < 12)) {
                    try {
                        temp = std::stoi(prompts[highlight].second);
                        if (temp < 20) {
                            temp++;
                            prompts[highlight].second = std::to_string(temp);
                        }
                    } catch (const std::exception& e) {}
                }
                break;
            case 10: // Enter
                if (highlight == done_index) done = true;
                else {
                    echo();
                    curs_set(1);
                    move(highlight + 2, 20);
                    getnstr(buffer, sizeof(buffer) - 1);
                    prompts[highlight].second = buffer;
                    noecho();
                    curs_set(0);
                }
                break;
        }
    }

    for (size_t i = 0; i < prompts.size(); i++) {
        if (i == 2 || i == 6) file << endl;
        file << "[" << prompts[i].first << "] : [" << prompts[i].second << "]" << endl; 
    }

    clear();
    mvaddstr(0, 0, "Character Creation Menu");
    mvaddstr(2, 1, "Player File written to:");
    mvaddstr(3, 1, target_path.string().c_str());
    mvaddstr(4, 1, "Press any key to continue...");
    getch();
}