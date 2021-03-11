#include "Bot.h"


Bot::Bot() {
    //Time measurement with chrono
    //Create a player
    unsigned int t0 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "I am a Roboter" << std::endl;
    std::cout << "Please enter a name for your character" << std::endl;
    std::string name = "Deathbunny 3000";
    std::unique_ptr<Player> player;
    player = std::make_unique<Player>(name);
    unsigned int t1 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    //Fight 
    std::cout << "Fight!!!!" << std::endl;
    std::unique_ptr<Enemy> enemy;
    enemy = std::make_unique<Enemy>(player->getTime(), player->getLevel());
    player->fight(enemy);
    std::cout << "You won the fight!" << std::endl;
    std::cout << "You have " << player->getCurrentHP() << " HP left" << std::endl;
    unsigned int t2 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    //Resting
    player->restoreHP();
    unsigned int t3 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    //Show stats
    player->showStats(); 
    unsigned int t4 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    //Get stats
    player->getSpecificStats();
    unsigned int t5 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    
    //Level up
    player->levelUp();
    unsigned int t6 = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    //Computing and printing results
    std::cout << std::endl;
    show1("Result of time measurement [microseconds]:");
    showi("Create Player", t1 - t0);
    showi("Fight", t2 - t1);
    showi("Resting", t3 - t2);
    showi("Show stats", t4 - t3);
    showi("Get stats", t5 - t4);
    showi("Level up", t6 - t5); 
}