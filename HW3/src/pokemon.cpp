/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#include <pokemon.h>
// Pokemon Constructor
Pokemon::Pokemon(std::string name, int hp, int damage, int powerUpChance, int recharge)
    : m_name(name), m_hp(hp), m_damage(damage), m_recharge(recharge), m_powerUpChance(powerUpChance) {
            // Boolean for faint
    m_isFainted=false;
    // Boolean for power up
    m_isPowerUp =false;
    // Boolean for on terrain
    m_isOnTerrain=false;
    }
// Getter method for if fainted
bool Pokemon::getFainted() const
{
    return this->m_isFainted;
}

// Getter method for name
std::string Pokemon::getName() const
{
    return m_name;
}
// Getter method for hp
int Pokemon::getHp() const
{
    return this->m_hp;
}
// Getter method for recharge
int Pokemon::getRecharge() const
{
    return this->m_recharge;
}
// Getter method for power up
bool Pokemon::getPowerUp() const
{
    return this->m_isPowerUp;
}
// Getter method for if on terrain
bool Pokemon::getOnTerrain() const
{
    return this->m_isOnTerrain;
};
// Setter method for hp
void Pokemon::setHp(int hp)
{
    this->m_hp = hp;
}
// Setter method to if power up
void Pokemon::setPowerUp(bool powerUp)
{
    this->m_isPowerUp = powerUp;
}
// Setter method for if on terrain
void Pokemon::setOnTerrain(bool onTerrain)
{
    this->m_isOnTerrain = onTerrain;
};
// Setter method for if fainted
void Pokemon::setFainted(bool fainted)
{
    this->m_isFainted = fainted;
}
// Power up method
void Pokemon::powerUp()
{
    // Random number generator
    int chance = rand() % 100;
    // If generated number is less than power up chance, power up(m_powerUpChance% chance)
    if (chance < this->m_powerUpChance)
    {
        this->m_isPowerUp = true;
    }
}