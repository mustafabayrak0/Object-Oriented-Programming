/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#include <arena.h>
// Constructor for arena
Arena::Arena()
{
    // Pointer to electric pokemon object
    m_electricPokemon = nullptr;
    // Pointer to psychic pokemon object
    m_psychicPokemon = nullptr;
    // Type of terrain
    terrain = "none";
    // Number of pokemons in arena
    m_numPokemons=0;
}

// Method to add pokemon
void Arena::addPokemon(char type, std::string name, int hp, int damage)
{
    // If type is electric
    if (type == 'e')
    {
        std::cout << "Electric Pokemon " << name << " has entered the arena. \n";
        std::cout << "Class: Electric \n"
                  << "Name: " << name << "\n"
                  << "HP: " << hp << "\n"
                  << "Damage: " << damage << "\n \n";
        this->m_electricPokemon = new ElectricPokemon(name, hp, damage, 20);
        this->m_numPokemons++;
    }
    // If type is psychic
    else if (type == 'p')
    {
        std::cout << "Psychic Pokemon " << name << " has entered the arena. \n";
        std::cout << "Class: Psychic \n"
                  << "Name: " << name << "\n"
                  << "HP: " << hp << "\n"
                  << "Damage: " << damage << "\n \n";
        this->m_psychicPokemon = new PsychicPokemon(name, hp, damage, 30);
        this->m_numPokemons++;
    }
    // If both pokemons are added set enemies
    if (this->m_numPokemons == 2)
    {
        this->m_psychicPokemon->setEnemy(this->m_electricPokemon);
        this->m_electricPokemon->setEnemy(this->m_psychicPokemon);
    }
}
// Method to simulate battle
void Arena::simulateBattle()
{
    // Reset the terrain at the beginning of each battle
    this->resetTerrain();
    // Round number
    int round = 1;
    // Charge counter for electric pokemon
    int electricChargeCounter = 3;
    // Charge counter for psychic pokemon
    int psychicChargeCounter = 5;

    // While both pokemons are alive
    while (!this->m_psychicPokemon->getFainted() && !this->m_electricPokemon->getFainted())
    {
        // Spawn terrain every 5 rounds if terrain is electric or psychic
        if (round - 1 % 5 == 0 && (this->terrain == "Electric" || this->terrain == "Psychic"))
        {
            // Set both pokemons not on terrain
            this->m_electricPokemon->setOnTerrain(false);
            this->m_psychicPokemon->setOnTerrain(false);
            this->spawnTerrain();
        }
        // Spawn terrain in each round if terrain is none
        else if (this->terrain == "none")
        {
            // Set both pokemons not on terrain
            this->m_electricPokemon->setOnTerrain(false);
            this->m_psychicPokemon->setOnTerrain(false);
            this->spawnTerrain();
        }
        // If psychic pokemon has chance to power up
        if (psychicChargeCounter >= this->m_psychicPokemon->getRecharge())
        {
            this->m_psychicPokemon->powerUp();
            if (this->m_psychicPokemon->getPowerUp())
            {
                psychicChargeCounter = -1;
            }
        }
        // If electric pokemon has chance to power up
        if (electricChargeCounter >= this->m_electricPokemon->getRecharge())
        {
            this->m_electricPokemon->powerUp();
            if (this->m_electricPokemon->getPowerUp())
            {
                electricChargeCounter = -1;
            }
        }

        // If terrain is electric
        if (this->terrain == "electric")
        {
            this->m_electricPokemon->setOnTerrain(true);
            this->m_electricPokemon->setConfused(false);
            this->m_electricPokemon->setConfusionRounds(0);
        }
        // If terrain is psychic
        else if (this->terrain == "psychic")
        {
            this->m_psychicPokemon->setOnTerrain(true);
        }
        int heads = rand() % 2;
        // If heads is 0, electric pokemon attacks first
        if (heads == 0)
        {
            this->m_electricPokemon->attack();
            if (!this->m_psychicPokemon->getFainted())
            {
                this->m_psychicPokemon->attack();
            }
        }
        // If heads is 1, psychic pokemon attacks first
        else
        {
            this->m_psychicPokemon->attack();
            if (!this->m_electricPokemon->getFainted())
            {
                this->m_electricPokemon->attack();
            }
        }

        // Print round stats
        this->printRoundStats(round, heads);
        // If rounds to end of confusion is 0, set confused to false
        if (this->m_electricPokemon->getConfusionRounds() == 0)
        {
            this->m_electricPokemon->setConfused(false);
        }
        // Increment round
        round++;
        // Set power up to false for both pokemons
        this->m_electricPokemon->setPowerUp(false);
        this->m_psychicPokemon->setPowerUp(false);
        // Increment charge counters
        electricChargeCounter++;
        psychicChargeCounter++;
    }
    // Print match results
    this->printMatchResults();
    // Delete electric pokemon
    delete this->m_electricPokemon;
    // Delete psychic pokemon
    delete this->m_psychicPokemon;
    // Set number of pokemons to 0
    this->m_numPokemons = 0;
}
void Arena::spawnTerrain()
{

    int rand_number = rand() % 10;
    // If random number is less than 2 (20% chance) spawn Electric type terrain
    if (rand_number < 2)
    {
        this->terrain = "psychic";
    }
    // If random number is less than 4 (20% chance) spawn Psychic type terrain
    else if (rand_number < 4)
    {
        this->terrain = "electric";
    }
    // If random number is greater than 3 (60% chance) spawn None type terrain
    else
    {
        this->terrain = "none";
    }
}

void Arena::resetTerrain()
{
    this->terrain = "none";
}
// Method to print round stats
void Arena::printRoundStats(int round, int heads)
{
    // Print round number
    std::cout << "Round: " << round << "\n";
    // Print current terrain
    std::cout << "Current terrain: " << this->terrain << "\n";
    // If order is 0 electric pokemon attacks first
    if (heads == 0)
    {
        // Print who attack first
        std::cout << this->m_electricPokemon->getName() << " goes first.\n";
    }
    // If order is 1 psychic pokemon attacks first
    else
    {
        // Print who attack first
        std::cout << this->m_psychicPokemon->getName() << " goes first.\n";
    }
    // If electric pokemon power up
    if (this->m_electricPokemon->getPowerUp() && !this->m_electricPokemon->getFainted())
    {
        // Print electric pokemon power up
        std::cout << this->m_electricPokemon->getName() << " has initiated a power up.\n";
    }
    // If psychic pokemon power up
    if (this->m_psychicPokemon->getPowerUp() && !this->m_psychicPokemon->getFainted())
    {
        // Print psychic pokemon power up
        std::cout << this->m_psychicPokemon->getName() << " has initiated a power up.\n";
    }

    // Print current HP of pokemons
    std::cout << this->m_electricPokemon->getName() << " HP: " << this->m_electricPokemon->getHp() << "\n";
    std::cout << this->m_psychicPokemon->getName() << " HP: " << this->m_psychicPokemon->getHp() << "\n";

    // Print the leader of the round
    if (this->m_electricPokemon->getHp() > this->m_psychicPokemon->getHp())
    {
        std::cout << this->m_electricPokemon->getName() << " is in the lead!\n \n";
    }
    else if (this->m_electricPokemon->getHp() < this->m_psychicPokemon->getHp())
    {
        std::cout << this->m_psychicPokemon->getName() << " is in the lead!\n \n";
    }
    else
    {
        std::cout << "It's a tie! \n \n";
    }
}
// Method to print match results
void Arena::printMatchResults()
{
    std::string winner;
    // If electric pokemon is fainted
    if (this->m_electricPokemon->getFainted())
    {
        winner = this->m_psychicPokemon->getName();
    }
    // If psychic pokemon is fainted
    else
    {
        winner = this->m_electricPokemon->getName();
    }

    // Print match result
    std::cout << "Match Results:\n"
              << winner << " has won the match!\n \n";
}