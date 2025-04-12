#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"
#include <stack>

using Command = std::function<void()>;

namespace game {
    class Game {
        render::Renderer &renderer;
        stack<scenes::Scene&> scenes;
        unordered_map<string, Command> command_map = {
            {"quit_game", []() {exit(0); }},
            {"open_sheet", []() {}}
        };

    public:
        Game(render::Renderer &renderer, scenes::Scene &scene) :
        renderer(renderer) {
            scenes.push(scene);
        }

        
    };
}  // namespace game

#endif  // GAME_H_
