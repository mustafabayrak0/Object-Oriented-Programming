/* @Author
* Student Name: Mustafa Bayrak
* Student ID : 150210339
*/
#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <random>
// Pokemon class
class Pokemon
{
public:
    // Pokemon Constructor
    Pokemon(std::string name, int hp, int damage, int powerUpChance, int recharge);

    // Method to get name
    std::string getName() const;
    // Method to get hp
    int getHp() const;
    // Method to get round number to recharge
    int getRecharge() const;
    // Method to get if power up
    bool getPowerUp() const;
    // Method to get if on terrain
    bool getOnTerrain() const;
    // Method to get if fainted
    bool getFainted() const;
    // Method to set hp
    void setHp(int);
    // Method to set if power up
    void setPowerUp(bool);
    // Method to set if on terrain
    void setOnTerrain(bool);
    // Method to set if fainted
    void setFainted(bool);
    // Method to power up
    void powerUp();
    // Method to attack
    virtual void attack() = 0;

protected:
    // Hit points
    int m_hp;
    // Name
    std::string m_name;
    // Damage
    const int m_damage;
    // Power up chance
    const double m_powerUpChance;
    // The number of rounds that must pass until a Pokemon has the chance to attempt to PowerUp again
    int m_recharge;
    // Boolean for faint
    bool m_isFainted;
    // Boolean for power up
    bool m_isPowerUp;
    // Boolean for on terrain
    bool m_isOnTerrain;
};

#endif // POKEMON_H
