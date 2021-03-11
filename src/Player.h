#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Enemy.h"
#include "Table.h"
#include <memory>



class Player{
protected:
    int currentHP = 100;
    unsigned int maxHP = 100;
    unsigned int attackPoints = 20;
    unsigned int defensePoints = 10;
    unsigned int level = 1;
    unsigned int gameTime = 0;
    std::string charName;
    std::string playerClass = "Trainee";

public:
// restore health function (max health upper bound)
    unsigned int getTime(){
        return this->gameTime;
    }
    
    std::string getName(){return charName;}
    int getCurrentHP (){return currentHP;}
    unsigned  int getMaxHP(){return maxHP;}
    unsigned int getAttPoints(){return attackPoints;}
    unsigned int getDefPoints(){return defensePoints;}
    unsigned int getLevel(){return level;}
    std::string getPlayerClass(){return playerClass;}

    // methods for derived clases
    virtual void levelUp();
    virtual void restoreHP();
    virtual void showStats();
    virtual void fight(std::unique_ptr<Enemy> &enemy);

    // save stats to get an vector that is
    // either empty if trainee 
    // 1 elem if fighter or
    // 3 if mage
    virtual std::vector<unsigned int> getSpecificStats();    

    Player(std::string name);
    Player(std::unique_ptr<Player> & player);
    Player(std::string name, std::string playerClass, unsigned int maxHP, unsigned int HP, unsigned int time, unsigned attackPoints, unsigned int defPoints, unsigned int level);
    virtual ~Player(){}
};
#endif
