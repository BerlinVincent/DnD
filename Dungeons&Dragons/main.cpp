#include <iostream>
#include "Framework/game_engine/Game.cpp"

/**
 * @brief Function for specific code segment testing, without changing main
 * @returns 1 if successful
 */
auto test() -> int {
    cout << "currently no test code" << endl;
    return 0;
}

auto main(int argc, char *argv[]) -> int {
    render::Renderer renderer;
    game::Game handler(renderer);
    
    test();

    return 0;
}
