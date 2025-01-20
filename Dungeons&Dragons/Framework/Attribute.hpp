#ifndef ATTRIBUTE_H_
#define ATTRIBUTE_H_

#include "inclusions.hpp"

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
int calculate_modifier(int attribute) {
    return (attribute - 10) / 2;
}

class Attribute {
    string name;
    int score;
    int attr_mod;

    public:
        string getName() {return name;}
        int getScore() {return score;}
        int getMod() {return attr_mod;}

        void setName(string new_name) {}
        void recalcMod() {attr_mod = calculate_modifier(score);}
        void scoreImprove() {score += 1;}
        void scoreDiminish() {if(getScore() >= 1) score -= 1;}

        Attribute() = default;
        Attribute(string new_name, int score) {
            setName(new_name);
            score = score;
            recalcMod();
        }
};

#endif // ATTRIBUTE_H_