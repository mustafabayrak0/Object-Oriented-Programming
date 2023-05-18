/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#include <psychicPokemon.h>
// Constructor for psychic pokemon
PsychicPokemon::PsychicPokemon(std::string name, int hp, int damage, int powerUpChance)
    : Pokemon(name, hp, damage, 30, 5) {
    // Enemy
    m_enemy = nullptr;
    }
// Setter method for enemy
void PsychicPokemon::setEnemy(ElectricPokemon *enemy)
{
    this->m_enemy = enemy;
}

// Method to attack
void PsychicPokemon::attack()
{
    // If it is power up
    if (this->m_isPowerUp && !this->m_enemy->getOnTerrain())
    {
        // Confuse enemy
        this->m_enemy->setConfused(true);
        this->m_enemy->setConfusionRounds(3);
    }
    // If it is on own terrain
    if (this->m_isOnTerrain)
    {
        // Give damage to enemy
        this->m_enemy->setHp(this->m_enemy->getHp() - this->m_damage);
        // If enemy is not fainted give damage again
        if (m_enemy->getHp() > 0)
        {
            this->m_enemy->setHp(this->m_enemy->getHp() - this->m_damage);
        }
    }
    // If it is not on own terrain
    else
    {
        // Give damage to enemy
        this->m_enemy->setHp(this->m_enemy->getHp() - this->m_damage);
    }
    // If HP is less than 0 set it to 0 and set fainted to true
    if (this->m_enemy->getHp() <= 0)
    {
        this->m_enemy->setHp(0);
        this->m_enemy->setFainted(true);
    }
}