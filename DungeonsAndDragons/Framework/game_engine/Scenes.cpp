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
    room_map(width, std::vector<char>(height, '.')),
    player_pos {width / 2, height / 2} {
    placePlayer(player_pos.first, player_pos.second);
}

auto Explore::inBounds(int x, int y) -> bool {
    return  y >= 0 && y < static_cast<int>(room_map.size()) &&
            x >= 0 && x < static_cast<int>(room_map[0].size());
}

void Explore::placeWall(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = 'X';
    else std::cerr << "Error placing Wall" << endl;
}

void Explore::placeGround(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = '.';
    else std::cerr << "Error placing Ground" << endl;
}

void Explore::placePlayer(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = '@';
    else std::cerr << "Error placing Player" << endl;
}

void Explore::placeEntity(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = '&';
    else std::cerr << "Error placing Entity" << endl;
}

void Explore::move(int key) {
    switch(key) {
        case KEY_UP:
            if (!inBounds(player_pos.first + 1, player_pos.second) ||
                room_map[player_pos.first + 1][player_pos.second] == 'X');
            else player_pos.first++;
        case KEY_DOWN:
            if (!inBounds(player_pos.first - 1, player_pos.second) ||
                room_map[player_pos.first - 1][player_pos.second] == 'X');
            else player_pos.first--;
        case KEY_LEFT:
            if (!inBounds(player_pos.first, player_pos.second - 1) ||
                room_map[player_pos.first][player_pos.second - 1] == 'X');
            else player_pos.second--;
        case KEY_RIGHT:
            if (inBounds(player_pos.first, player_pos.second + 1) ||
                room_map[player_pos.first][player_pos.second + 1] == 'X');
            else player_pos.second++;
    }
}