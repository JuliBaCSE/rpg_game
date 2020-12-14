#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>


class Enemy{
public:
    int HP = 100;
    unsigned int attackPoints = 15;
    unsigned int defensePoints = 5;
    std::string enemyName = "goblin";

    Enemy();

};
#endif
