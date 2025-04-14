#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"
#include <stack>

namespace game {
    class Game {
        render::Renderer &renderer;
        stack<scenes::Scene&> scenes;

    public:
        Game(render::Renderer &renderer, scenes::Scene &scene) :
        renderer(renderer) {
            scenes.push(scene);
        }
    };
}  // namespace game

#endif  // GAME_H_
