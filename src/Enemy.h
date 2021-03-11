#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>


class Enemy{
private:
    std::vector <std::string> goblin = { "Grubfoot", "General Bentnoze",
    "General Wartface", "Lumpnose", "Mosschin", "Mossfists", "Mudfoot",
     "Mudknuckles", "Slimetoes", "Smellytoes", "Snailfeet", "Snothead",
     "Wormbrain", "Professor Bader", "Doktor Neckel", "Admiral Hasan",
     "Comander Chourdakis", "General Hayden"}; 

public:
    std::string enemyName = "goblin " + goblin[rand() % 18];
    unsigned int attackPoints = 15;
    unsigned int defensePoints = 5;
    int HP = 90;

    // need to creat stronger Goblin if level of Player gets higher
    Enemy(unsigned int gametime, unsigned int level);
};
#endif