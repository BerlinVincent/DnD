#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"
namespace game {
    class Game
    {
        render::Renderer &renderer;

    public:
        Game(render::Renderer &renderer)
            : renderer(renderer)
        {

        }
    }
}


#endif // GAME_H_
