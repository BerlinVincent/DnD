#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.hpp"

namespace game {
    class Player : public Entity {
        bool inspiration;
        
        // Player Game Skills
        vector<Skill> skills;

        public:
            using Entity::Entity;
            Player(string name, string descriptor, Alignment alignment, int max_health, int experience, uint proficiency_bonus, vector<Attribute> attributes, vector<bool> proficiencies)
            : Entity(name, descriptor, alignment, max_health, experience, proficiency_bonus, attributes, proficiencies) {

                this->inspiration = false;

                
                /* Feature for later
                this-> skills = {
                    Skill("acrobatics",         getAttributes().at(DEX), proficiencies.at(acrobatics)),
                    Skill("animal_handling",    getAttributes().at(WIS), proficiencies.at(animal_handling)),
                    Skill("arcana",             getAttributes().at(INT), proficiencies.at(arcana)),
                    Skill("athletics",          getAttributes().at(STR), proficiencies.at(athletics)),
                    Skill("deception",          getAttributes().at(CHA), proficiencies.at(deception)),
                    Skill("history",            getAttributes().at(INT), proficiencies.at(history)),
                    Skill("insight",            getAttributes().at(WIS), proficiencies.at(insight)),
                    Skill("intimidation",       getAttributes().at(CHA), proficiencies.at(intimidation)),
                    Skill("investigation",      getAttributes().at(INT), proficiencies.at(investigation)),
                    Skill("medicine",           getAttributes().at(WIS), proficiencies.at(medicine)),
                    Skill("nature",             getAttributes().at(INT), proficiencies.at(nature)),
                    Skill("perception",         getAttributes().at(WIS), proficiencies.at(perception)),
                    Skill("performance",        getAttributes().at(CHA), proficiencies.at(performance)),
                    Skill("persuasion",         getAttributes().at(CHA), proficiencies.at(persuasion)),
                    Skill("religion",           getAttributes().at(INT), proficiencies.at(religion)),
                    Skill("sleight_of_hand",    getAttributes().at(DEX), proficiencies.at(sleight_of_hand)),
                    Skill("stealth",            getAttributes().at(DEX), proficiencies.at(stealth)),
                    Skill("survival",           getAttributes().at(WIS), proficiencies.at(survival))
                }; */
            }
    };
}


#endif // PLAYER_H_
