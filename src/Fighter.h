#ifndef FIGHTER_H
#define FIGHTER_H

#include "Player.h"
#include <cstdlib>
#include <memory>
#include "Table.h"

class Fighter : public Player{
private:
    unsigned int critChance = 1;
public:
    void showStats() override;
    void levelUp() override;
    void fight(std::unique_ptr<Enemy> &enemy) override;

    virtual std::vector<unsigned int> getSpecificStats() override;
    Fighter(std::unique_ptr<Player>  & player);
    Fighter(std::string name, std::string playerClass,
     unsigned int maxHP, unsigned int HP,
     unsigned int time, unsigned attackPoints,
     unsigned int defPoints, unsigned int level,
     unsigned int critChance);
     ~Fighter(){}    
};
#endif