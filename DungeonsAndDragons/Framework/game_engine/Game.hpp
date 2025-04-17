#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"
#include <stack>

namespace game {
    struct Gamestate {
        render::Renderer& renderer;
        stack<scenes::Scene> scenes;

        Gamestate(render::Renderer& renderer, scenes::Scene& scene) :
            renderer(renderer) {
                scenes.push(scene);
            }
    };

    class Game {
        Gamestate gamestate;

    public:
        Game(render::Renderer& renderer, scenes::Scene& scene) :
            gamestate(renderer, scene) {}
    };

}  // namespace game

#endif  // GAME_H_
