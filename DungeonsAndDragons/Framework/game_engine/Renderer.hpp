#ifndef RENDERER_H_
#define RENDERER_H_

#include "../entities/Player.hpp"
#include "Scenes.hpp"

namespace render {

    class Renderer {
    public:
        Renderer();

        virtual auto render(const Player &player, const scenes::Scene &scene) -> bool {return true;}
    };

}  // namespace render

#endif  // RENDERER_H_
