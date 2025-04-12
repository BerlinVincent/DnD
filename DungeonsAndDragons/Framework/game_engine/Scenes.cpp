#include "Scenes.hpp"
#include <ncurses.h>

using namespace scenes;

Combat::Combat(Player& player, Entity& enemy) :
    player(player),
    enemy(enemy),
    act() {
    turn = 0;
}

void Combat::playerAttack() {
    act.attack(player, enemy);
}

void Combat::enemyAttack() {
    act.attack(enemy, player);
}

Explore::Explore(int width, int height) :
    room_map(width, vector<char>(height, '.')),
    player_pos {width / 2, height / 2} {
    placeObj(player_pos.first, player_pos.second, '@');
}

auto Explore::inBounds(int x, int y) -> bool {
    return  y >= 0 && y < static_cast<int>(room_map.size()) &&
            x >= 0 && x < static_cast<int>(room_map[0].size());
}

void Explore::placeObj(int x, int y, char Obj) {
    if (inBounds(x, y)) room_map[x][y] = Obj;
    else cerr << "Out of bounds coordinates for " + Obj << endl;
}

void Explore::move(int key) {
    switch(key) {
        case KEY_UP:
            if (!inBounds(player_pos.first + 1, player_pos.second) ||
                room_map[player_pos.first + 1][player_pos.second] == 'X');
            else player_pos.second--;
        case KEY_DOWN:
            if (!inBounds(player_pos.first - 1, player_pos.second) ||
                room_map[player_pos.first - 1][player_pos.second] == 'X');
            else player_pos.second++;
        case KEY_LEFT:
            if (!inBounds(player_pos.first, player_pos.second - 1) ||
                room_map[player_pos.first][player_pos.second - 1] == 'X');
            else player_pos.first--;
        case KEY_RIGHT:
            if (inBounds(player_pos.first, player_pos.second + 1) ||
                room_map[player_pos.first][player_pos.second + 1] == 'X');
            else player_pos.first++;
    }
}

Sheet::Sheet(ifstream &file) {
    string line, label, effect;
    regex pattern_option(R"(^\s*Option\s*:\s*(.+)\s*$)");
    regex pattern_effect(R"(^\s*Command\s*:\s*(.+)\s*$)");
    regex pattern_sep("^-+$");
    smatch match;

    while (getline(file, line)) {
        if (regex_match(line, match, pattern_option)) {
            label = match[1];
        } else if (regex_match(line, match, pattern_effect)) {
            effect = match[1];
        } else if (regex_match(line, match, pattern_sep)) {
            options.push_back({label, effect});
        }
    }
}