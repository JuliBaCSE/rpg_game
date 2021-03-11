#ifndef MAGE_H
#define MAGE_H

#include <memory>
#include "Player.h"
#include <cstdlib>

class Mage : public Player{
private:
    unsigned int currentMana = 100;
    unsigned int maxMana = 100;
    unsigned int magicDamage = 50;
public:

    void showStats() override;
    void restoreHP() override;
    void levelUp() override;
    void fight(std::unique_ptr<Enemy> &enemy) override;

    virtual std::vector<unsigned int> getSpecificStats() override;

    Mage(std::unique_ptr<Player>  & player);
    Mage(std::string name, std::string playerClass,
     unsigned int maxHP, unsigned int HP,
     unsigned int time, unsigned attackPoints,
     unsigned int defPoints, unsigned int level,
     unsigned int magicDamage,
     unsigned int maxMana, unsigned int currentMana);
     ~Mage(){}    
};
#endif