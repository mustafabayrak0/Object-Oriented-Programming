/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#include <electricPokemon.h>
#include <iostream>
#include <psychicPokemon.h>
#include <random>

// Arena class
class Arena
{
public:
    // Declare constructor
    Arena();
    // Method to add pokemon
    void addPokemon(char type, std::string name, int hp, int damage);
    // Method to simulate battle
    void simulateBattle();
    // Method to spawn terrain
    void spawnTerrain();
    // Method to restart terrain
    void resetTerrain();
    // Method to print round stats
    void printRoundStats(int round, int heads);
    // Method to print match results
    void printMatchResults();

private:
    // Pointer to electric pokemon object
    ElectricPokemon *m_electricPokemon;
    // Pointer to psychic pokemon object
    PsychicPokemon *m_psychicPokemon;
    // Type of terrain
    std::string terrain;
    // Number of pokemons in arena
    int m_numPokemons;
};