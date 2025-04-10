#include "Scenes.hpp"

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
}

void Explore::placeGround(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = '.';
}

void Explore::placePlayer(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = '@';
}

void Explore::placeEntity(int x, int y) {
    if (inBounds(x, y)) room_map[x][y] = '&';
}