#include "Mage.h"

Mage::Mage(std::unique_ptr<Player> & player):Player(player){
    playerClass = "Mage";
}
Mage::Mage(std::string name, std::string playerClass,
    unsigned int maxHP, unsigned int currentHP,
    unsigned int time, unsigned attackPoints,
    unsigned int defPoints, unsigned int level,
    unsigned int magicDamage, unsigned int maxMana, unsigned int currentMana):
    Player(name, playerClass,
     maxHP, currentHP,
      time, attackPoints,
     defPoints, level), magicDamage(magicDamage), maxMana(maxMana), currentMana(currentMana){}
void Mage::showStats(){
    std::cout << "Hello " << playerClass << " " << charName
        << std::endl << "That are your stats:" << std::endl << std::endl;
    showi("Level:", level);
    showi("HP:", currentHP);
    showi("Max HP:", maxHP);
    showi("Attackpoints:", attackPoints);
    showi("Defensivepoints:", defensePoints);
    showi("Magic damage:", magicDamage);
    showi("Current Mana:", currentHP);
    showi("Max Mana:", maxMana);
    showi("Your ingame time is:", gameTime); 
}
void Mage::restoreHP(){
    std::cout << "Healing started and Mana restoring stared!" << std::endl;
    if(currentHP + 10 >= maxHP){
        currentHP = maxHP;
        std::cout << "Your health is fully recovered" <<std::endl;
    }
    else{
        currentHP = maxHP;
        std::cout << "You are now healed" << std::endl;
    }
    if(currentMana + 10 >= maxMana){
        currentMana = maxMana;
        std::cout << "Your Mana is fully recovered" <<std::endl;
    }
    else{
        currentMana = maxMana;
        std::cout << "You restored your mana points" << std::endl;
    }
    this->gameTime++;
}
void Mage::levelUp(){
    std::cout << "Congratulations you leveled up!!" << std::endl;
    this->level++;
    this->defensePoints = defensePoints + 5;
    this->attackPoints = attackPoints + 5;
    this->magicDamage = magicDamage + 10;
    this->maxHP = maxHP + 20;
    this->maxMana = maxMana + 30;
    std::cout << "You gained some new Stats!!" <<std::endl;
    std::cout << "Your new Level is: " << this->level << std::endl;
}
void Mage::fight(std::unique_ptr<Enemy> &enemy){
    std::cout << "Your Enemy is the famous " << enemy->enemyName << "!!!"<<std::endl;
    int damageToPlayer = 0;
    int damageToEnemy = 0;
    int manaPerSpell = 50;
    if (currentMana > manaPerSpell){
        damageToEnemy = enemy->defensePoints - this->magicDamage;
        std::cout << "You casted a magic Spell!!!" << std::endl;
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
std::vector<unsigned int> Mage::getSpecificStats(){
    std::vector<unsigned int> mageStats = {currentMana, maxMana, magicDamage};
    return mageStats;
}