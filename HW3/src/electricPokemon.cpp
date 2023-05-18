/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#include <electricPokemon.h>
// Constructor for electric pokemon
ElectricPokemon::ElectricPokemon(std::string name, int hp, int damage, int powerUpChance)
    : Pokemon(name, hp, damage, 20, 3) {
            // Boolean to check if confused
    this->m_confused=false;
    // Enemy
    m_enemy=nullptr;
    // Number of rounds last to end of confusion
    m_confusionRounds=0;
    }
// Getter method for confused
bool ElectricPokemon::getConfused() const
{
    return m_confused;
}
// Method to get enemy
PsychicPokemon *ElectricPokemon::getEnemy() const
{
    return this->m_enemy;
}
// Method to get confusion rounds
int ElectricPokemon::getConfusionRounds() const
{
    return this->m_confusionRounds;
}
// Setter method for enemy
void ElectricPokemon::setEnemy(PsychicPokemon *enemy)
{
    this->m_enemy = enemy;
}

// Setter method for confused
void ElectricPokemon::setConfused(bool confused)
{
    this->m_confused = confused;
}
// Setter method for confusion rounds
void ElectricPokemon::setConfusionRounds(int rounds)
{
    this->m_confusionRounds = rounds;
}

// Method to attack
void ElectricPokemon::attack()
{
    // If electric pokemon is confused
    if (this->m_confused)
    {
        // Decrement rounds to end of confusion
        this->m_confusionRounds--;
    }
    else
    {
        // If it is power up
        if (this->m_isPowerUp)
        {
            // Give damage to enemy
            this->m_enemy->setHp(this->m_enemy->getHp() - 3 * this->m_damage);
        }
        // If not power up
        else
        {
            // Give damage to enemy
            this->m_enemy->setHp(this->m_enemy->getHp() - this->m_damage);
        }
    }
    // If HP is less than 0 set it to 0 and set fainted to true
    if (this->m_enemy->getHp() <= 0)
    {
        this->m_enemy->setHp(0);
        this->m_enemy->setFainted(true);
    }
}
