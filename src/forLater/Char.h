#ifndef CHAR_H
#define CHAR_H

#include "Enemy.h"
#include <iostream>

class Char{
private:
    int _HP = 100;
    unsigned int _attackPoints = 20;
    unsigned int _defensePoints = 10;
    const std::string _charName;

    friend class Player;
    friend class Enemy;
public:
    std::string getName() const;
    int getHP() const;
    Char(int HP, unsigned int attackPoints, unsigned int defensePoints, std::string charName);
};


#endif