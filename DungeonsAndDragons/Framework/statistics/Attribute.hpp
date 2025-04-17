#ifndef ATTRIBUTE_HPP_
#define ATTRIBUTE_HPP_

#include "../inclusions.hpp"

/**
 * @brief An enum for the order and names of the attributes in Dungeons&Dragons
 */
enum Attributes {
    STR,
    DEX,
    CON,
    INT,
    WIS,
    CHA
};

/**
 * @brief A function to calculate modifiers from attributes.
 * @authors BerlinVincent
 */
int calculate_modifier(int attribute);

/**
* @brief A class for character Attributes of Dungeons&Dragons
* @details Attributes need to be identifiable by name, contain an attribute score and optimally the attribute modifier.
* @authors BerlinVincent
*/
class Attribute {
    string name;
    int score;
    int attr_mod;

    public:
        auto getName() -> string;
        auto getScore() -> int;
        auto getMod() -> int;

        void recalcMod();
        void scoreImprove();
        void scoreDiminish();

        Attribute() = default;
        Attribute(string name, int score);
};

#endif // ATTRIBUTE_HPP_