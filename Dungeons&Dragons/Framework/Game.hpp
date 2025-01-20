#ifndef GAME_H_
#define GAME_H_

#include "Renderer.hpp"
namespace game {
    class Game
    {
        render::UI &renderer;

    public:
        Game(render::UI &renderer)
            : renderer(renderer)
        {

        }
    }
}


#endif // GAME_H_
