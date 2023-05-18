/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#ifndef ELECTRIC_POKEMON_H
#define ELECTRIC_POKEMON_H

#include <pokemon.h>
#include <psychicPokemon.h>
// Forward declaration of PsychicPokemon class
class PsychicPokemon;
// Electric Pokemon class
class ElectricPokemon : public Pokemon
{
public:
    // Constructor for electric pokemon
    ElectricPokemon(std::string name, int hp, int damage, int powerUpChance);

    // Method to get confused
    bool getConfused() const;
    // Method to get enemy
    PsychicPokemon *getEnemy() const;
    // Getter method for confusion rounds
    int getConfusionRounds() const;
    // Method to set confused
    void setConfused(bool);
    // Setter method for confusion rounds
    void setConfusionRounds(int);
    // Setter method for enemy
    void setEnemy(PsychicPokemon *);
    // override attack method
    void attack() override;

private:
    // Boolean to check if confused
    bool m_confused;
    // Enemy
    PsychicPokemon *m_enemy;
    // Number of rounds last to end of confusion
    int m_confusionRounds;
};

#endif // ELECTRIC_POKEMON_H
