#ifndef RENDERER_H_
#define RENDERER_H_

#include "entities/Player.hpp"
#include "Scenes.hpp"
namespace render {

    class Renderer {
        virtual auto render(const game::Player &player,
                            const scenes::Scene &) -> bool;
    };
}  // namespace render

#endif  // RENDERER_H_
