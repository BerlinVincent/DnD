#ifndef RENDERER_H_
#define RENDERER_H_

#include "../entities/Player.hpp"
#include "Scenes.hpp"

namespace render {

    class Renderer {
        virtual auto render(const Entity &player,const scenes::Scene &) -> bool {return true;}
    };
}  // namespace render

#endif  // RENDERER_H_
