#ifndef RENDERER_H_
#define RENDERER_H_

#include "../entities/Entity.cpp"
#include "Scenes.hpp"

namespace render {

    class Renderer {
        virtual auto render(const Entity &player,const scenes::Scene &) -> bool;
    };
}  // namespace render

#endif  // RENDERER_H_
