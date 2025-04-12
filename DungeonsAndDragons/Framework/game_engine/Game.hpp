#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"

using Command = std::function<void()>;

namespace game {
    class Game {
        render::Renderer &renderer;
        scenes::Scene &scene;
        unordered_map<string, Command> command_map = {
            {"quit_game", []() {exit(0); }},
            
        };

    public:
        Game(render::Renderer &renderer, scenes::Scene &scene) :
        renderer(renderer), scene(scene) {
            
        }

        
    };
}  // namespace game

#endif  // GAME_H_
