#ifndef GAME_H_
#define GAME_H_

#include "Renderer.cpp"
namespace game {
    class Game {
        render::Renderer &renderer;

    public:
        Game(render::Renderer &renderer)
            : renderer(renderer) {
                
        }
    };
}  // namespace game

#endif  // GAME_H_
