#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"
namespace game {
    class Game {
        render::Renderer& renderer;
        scenes::Scene& scene;

    public:
        Game(render::Renderer& renderer, scenes::Scene& scene) :
        renderer(renderer), scene(scene) {
            
        }

        
    };
}  // namespace game

#endif  // GAME_H_
