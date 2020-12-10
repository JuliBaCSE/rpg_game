#include "Player.h"



Player::Player(std::string name): charName(name){}
Player::Player(std::string name, unsigned int HP, unsigned int time): charName(name), HP(HP), gameTime(time){}

void Player::restoreHP(){
    std::cout << "Healing started!" << std::endl;
    if(HP + 10 >= 100){
        HP = 100;
        std::cout << "Your are fully recovered" <<std::endl;
    }
    else{
        HP +=10;
        std::cout << "You healed 10 points" << std::endl;
    }
    this->gameTime++;
}
void Player::showStats(){
    std::cout <<"Hello "<< charName << " your HP is " << HP << ", your attackpoints are " << attackPoints << " and your defensivepoints are " << defensePoints << std::endl; 
    std::cout <<"Your ingame time is "<< gameTime << std::endl;    
}
void Player::fight(std::unique_ptr<Enemy> &enemy){
    std::cout << "Your Enemy is a " << enemy->enemyName << std::endl;
    int damageToPlayer = 0;
    int damageToEnemy = 0;
    damageToPlayer = this->defensePoints - enemy->attackPoints;
    damageToEnemy = enemy->defensePoints - this->attackPoints;

    std::cout << damageToEnemy << damageToPlayer << std::endl;

    if(damageToEnemy > 0){
        damageToEnemy = 0;
    }
    else if(damageToPlayer>0){
        damageToPlayer=0;
    }

    while(enemy->HP > 0 && this->HP > 0){
        this->HP = this->HP + damageToPlayer;
        enemy->HP = enemy->HP + damageToEnemy;

        std::cout << this->HP << enemy->HP << std::endl;
    }

    this->gameTime++;
    // damage = attack points - defense points
    // damage >=0
    //fight = for loop till one die
    //increment ingame time
}
