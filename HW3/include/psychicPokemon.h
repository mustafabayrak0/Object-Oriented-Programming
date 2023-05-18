/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#ifndef PSYCHIC_POKEMON_H
#define PSYCHIC_POKEMON_H

#include <electricPokemon.h>
#include <pokemon.h>
// Forward declaration of ElectricPokemon class
class ElectricPokemon;
// Psychic Pokemon class
class PsychicPokemon : public Pokemon
{
public:
    // Constructor for psychic pokemon
    PsychicPokemon(std::string name, int hp, int damage, int powerUpChance);

    // Method to set enemy
    void setEnemy(ElectricPokemon*);
    // override attack method
    void attack() override;

private:
    // Enemy
    ElectricPokemon *m_enemy;
};

#endif // PSYCHIC_POKEMON_H
