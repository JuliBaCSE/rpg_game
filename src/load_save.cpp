#include "load_save.h"
#include "memory"
#include<fstream>
#include<sstream>

std::unique_ptr<Player> loadSavedStats(std::string filename)
{
    std::ifstream csv_file(filename);
    if(csv_file.is_open()){
        std::string name;
        int HP;
        unsigned int time;
// load time 
        csv_file>>name;
        csv_file>>HP;
        csv_file>>time;
        std::unique_ptr<Player> newPlayer;
        newPlayer = std::make_unique<Player>(name,HP,time);

        csv_file.close();
        return newPlayer;
    }
    else{
        std::cout << "couldn't open the file" << std::endl;
    }
    std::unique_ptr<Player> newPlayer;
    newPlayer = std::make_unique<Player>("Unknown");
    return newPlayer;
}

void saveStats(std::unique_ptr<Player> &player, std::string filename){
    std::ofstream csv_file(filename);
    if(csv_file.is_open()){
        csv_file << player->getName() << "\n";
        csv_file << player->getHP()<< "\n";
        csv_file << player->getTime();
        csv_file.close();
    }
    else{
        std::cout << "couldn't save stats" << std::endl;
    }
}