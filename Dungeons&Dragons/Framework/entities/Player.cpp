#ifndef PLAYER_C_
#define PLAYER_C_

#include "Player.hpp"

auto Player::getClass() -> string& {
    return player_class.name;
}

auto Player::getGear() -> vector<string>& {
    return gear;
}

#endif // PLAYER_C_