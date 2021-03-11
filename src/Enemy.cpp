#include "Enemy.h"

Enemy::Enemy(unsigned int gametime, unsigned int level){
    std::cout<<"A golbin crossed your way!" <<std::endl;
    std::cout << "He is going to attack YOU!!" <<std::endl;

    //Enemy gets better stats with increasing time and level of the player
    attackPoints =attackPoints+ gametime + 3*level;
    defensePoints =defensePoints+ gametime + 3 * level;
    HP = HP+ 5*gametime + 10 * level;
}