#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Enemy.h"


class Player{
private:
//2 new var attack points and defense points ingame time
    int HP = 100;
    unsigned int attackPoints = 20;
    unsigned int defensePoints = 10;
    unsigned int gameTime = 0;
    std::string charName;

public:
// restore health function (max health upper bound)
    unsigned int getTime(){
        return this->gameTime;
    }
    void restoreHP();
    std::string getName(){return charName;}
    int getHP (){return HP;}
    unsigned int getAttPoints(){return attackPoints;}
    unsigned int getDefPoints(){return defensePoints;}


//show stats function ggf besser ordnen vielleicht tabelle
    void showStats();

    void fight(std::unique_ptr<Enemy> &enemy);

    Player(std::string name);
    Player(std::string name, unsigned int HP, unsigned int time, unsigned attackPoints, unsigned int defPoints);
};


#endif
