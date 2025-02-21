#ifndef CREATION_ENGINE_H_
#define CREATION_ENGINE_H_

#include <filesystem>
#include "../inclusions.hpp"
#include "../entities/Player.cpp"

class CreationEngine {
    public:
        /**
         * @brief A function to create an Entity based on data in a file
         * @param file The file containing the Entity data
         * @returns The created Entity
         */
        auto createEntity(ifstream &file) -> Entity *;

        /**
         * @brief A function to create an Entity in a menu
         * @returns The created Entity
         */
        auto createCustomEntity() -> Entity *;
};

#endif // CREATION_ENGINE_H_