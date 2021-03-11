#include "Fighter.h"



Fighter::Fighter(std::unique_ptr<Player> & player):Player(player){
    playerClass = "Fighter";
}
Fighter::Fighter(std::string name, std::string playerClass,
    unsigned int maxHP, unsigned int currentHP,
    unsigned int time, unsigned attackPoints,
    unsigned int defPoints, unsigned int level,
    unsigned int critChance):
    Player(name, playerClass,
     maxHP, currentHP,
      time, attackPoints,
     defPoints, level), critChance(critChance){}
void Fighter::showStats(){
    std::cout << "Hello " << playerClass << " " << charName << std::endl
        << "That are your stats:" <<std::endl <<std::endl;
    showi("Level:", level);
    showi("Current HP:" , currentHP);
    showi("Max HP:", maxHP);
    showi("Attackpoints:", attackPoints);
    showi("Defensivepoints:", defensePoints);
    showi("Crit chance: [%] ", 10 * critChance);
    showi("Image time:", gameTime);
}

void Fighter::levelUp(){
    std::cout << "Congratulations you leveled up!!" << std::endl;
    this->level++;
    this->defensePoints = defensePoints + 10;
    this->attackPoints = attackPoints + 10;
    this->critChance = critChance + 1;
    std::cout << "You gained some new Stats!!" <<std::endl;
    std::cout << "Your new Level is: " << this->level << std::endl;
}
void Fighter::fight(std::unique_ptr<Enemy> &enemy){
    std::cout << "Your Enemy is the famous " << enemy->enemyName << "!!!"<<std::endl;
    int damageToPlayer = 0;
    int damageToEnemy = 0;

    bool criticalStrike = critChance > (rand() % 10 + 1); 
    if (criticalStrike){
        damageToEnemy = enemy->defensePoints - 1.5*(this->attackPoints);
        std::cout << "You did a critical strike!!!" << std::endl;
    }
    else{
        damageToEnemy = enemy->defensePoints - this->attackPoints;
    }
    damageToPlayer = this->defensePoints - enemy->attackPoints;

    if(damageToEnemy > 0){
        damageToEnemy = 0;
    }
    else if(damageToPlayer>0){
        damageToPlayer=0;
    }
    showi("Your damge is:", -damageToPlayer);
    showi(("The " + enemy->enemyName + " damage is: "), -damageToEnemy);
    int round = 1;
    while(enemy->HP > 0 && this->currentHP > 0){
        if (this->currentHP + damageToPlayer > 0) {
            this->currentHP = this->currentHP + damageToPlayer;
        }
        else { //avoid overflow of unsigned int
            this->currentHP = 0;
        }
        if (enemy->HP + damageToEnemy > 0) {
            enemy->HP = enemy->HP + damageToEnemy;
        }
        else {
            enemy->HP = 0;
        }
        std::cout << "Fight round: " << round << std::endl;
        showi("Your HP are:", this->currentHP);
        showi(("The " + enemy->enemyName + " HP are:"), enemy->HP);
        round++;
    }
    this->gameTime++;
}

std::vector<unsigned int> Fighter::getSpecificStats(){
    std::vector<unsigned int> crit = {critChance};
    return crit;
}