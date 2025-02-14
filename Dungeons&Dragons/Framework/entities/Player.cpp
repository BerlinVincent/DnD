#include "Player.hpp"

auto Player::getClass() -> string& {
    return player_class.name;
}

auto Player::getGear() -> vector<string>& {
    return gear;
}