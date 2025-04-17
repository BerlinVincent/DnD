#ifndef CREATION_ENGINE_H_
#define CREATION_ENGINE_H_

#include <filesystem>
#include "../inclusions.hpp"
#include "../entities/Player.hpp"

class CreationEngine {
    public:
        /**
         * @brief A function to create an Entity based on data in a file
         * @param file The file containing the Entity data
         * @returns The created Entity
         * @author BerlinVincent
         */
        auto createEntity(ifstream &file) -> Entity *;

        /**
         * @brief A function to create an Entity in a menu
         * @author BerlinVincent
         */
        void createCustomEntity();

        /**
         * @brief A function to create a Player File in a menu
         * @author BerlinVincent
         */
        void createPlayerFile();

};

#endif // CREATION_ENGINE_H_