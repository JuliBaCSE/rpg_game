#include "Player.h"

Player::Player(std::string name): charName(name){}
Player::Player(std::unique_ptr<Player> &from_player){
    charName = from_player->charName;
    playerClass = from_player->playerClass;
    maxHP = from_player->maxHP;
    currentHP = from_player->currentHP;
    gameTime = from_player->gameTime;
    attackPoints = from_player->attackPoints;
    defensePoints = from_player->defensePoints;
    level = from_player->level;
}

Player::Player(std::string name,std::string playerClass, unsigned int maxHP, unsigned int HP, unsigned int time,unsigned attackPoints, unsigned int defPoints, unsigned int level):
    playerClass(playerClass),charName(name), maxHP(maxHP), currentHP(HP), gameTime(time),
    attackPoints(attackPoints), defensePoints(defPoints), level(level){}

void Player::restoreHP(){
    std::cout << "Healing started!" << std::endl;
    if(currentHP != maxHP){
        currentHP = maxHP;
        std::cout << "You are now healed" <<std::endl;
    }
    else{
        currentHP = maxHP;
        std::cout << "Your are already fully recovered" << std::endl;
    }
    this->gameTime++;
}
void Player::showStats(){
    std::cout << "Hello " << playerClass << " " << charName 
    << std::endl << "That are your stats:" << std::endl<< std::endl;
    showi( "Level:", level );
    showi("HP:", currentHP);
    showi("Max HP:", maxHP);
    showi( "Attackpoints:", attackPoints);
    showi( "Defensivepoints:", defensePoints);
    showi("Your ingame time is:", gameTime);
}
void Player::fight(std::unique_ptr<Enemy> &enemy){
    std::cout << "Your Enemy is the famous " << enemy->enemyName << "!!!"<<std::endl;
    int damageToPlayer = 0;
    int damageToEnemy = 0;
    damageToPlayer = this->defensePoints - enemy->attackPoints;
    damageToEnemy = enemy->defensePoints - this->attackPoints;

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
void Player::levelUp(){
    std::cout << "Congratulations you leveled up!!" << std::endl;
    this->level++;
    this->defensePoints = defensePoints + 5;
    this->attackPoints = attackPoints + 5;
    this->maxHP = maxHP + 20;
    std::cout << "You gained some new Stats!!" <<std::endl;
    std::cout << "Your new Level is: " << this->level << std::endl;
}
std::vector<unsigned int> Player::getSpecificStats(){
    std::vector<unsigned int> stats;
    return stats;
}