#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

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

/** This belongs in a .cpp file
 * @brief A function to calculate modifiers from attributes.
 * @authors BerlinVincent
 */
int calculate_modifier(int attribute) {
    return (attribute - 10) / 2;
}

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
        string getName() {return name;}
        int getScore() {return score;}
        int getMod() {return attr_mod;}

        void recalcMod() {attr_mod = calculate_modifier(score);}
        void scoreImprove() {score += 1;}
        void scoreDiminish() {if(getScore() >= 1) score -= 1;}

        Attribute() = default;
        Attribute(string name, int score) {
            this->name = name;
            this-> score = score;
            recalcMod();
        }
};

#endif // ATTRIBUTE_H_