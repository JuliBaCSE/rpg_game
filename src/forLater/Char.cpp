#include "Char.h"

Char::Char(int HP, unsigned int attackPoints, unsigned int defensePoints, std::string charName):
    _HP(HP),
    _attackPoints(attackPoints),
    _charName(charName)
    {
        std::cout << "A Char has been greated: "<< _charName << std::endl;
    }

std::string Char::getName() const{
        return _charName;
    }
int Char::getHP() const{
    return _HP;
}