#include "load_save.h"


std::unique_ptr<Player> loadSavedStats(std::string filename)
{   
    filename = "../saves/saved_stats/" + filename;
    std::ifstream csv_file(filename);
    if(csv_file.is_open()){
        std::string name;
        std::string playerClass;
        unsigned int maxHP;
        int currentHP;
        unsigned int time;
        unsigned int attackPoints;
        unsigned int defPoints;
        unsigned int level; 
// load time 
        csv_file>>name;
        csv_file>>playerClass;
        csv_file>>maxHP;
        csv_file>>currentHP;
        csv_file>>time;
        csv_file>>attackPoints;
        csv_file>>defPoints;
        csv_file>>level;

        if(playerClass == "Mage"){
            unsigned int currentMana;
            unsigned int maxMana;
            unsigned int magicDamage; 
            csv_file>>currentMana;
            csv_file>>maxMana;
            csv_file>>magicDamage;
            std::unique_ptr<Player> newPlayer;
            newPlayer = std::make_unique<Mage>(
                name,playerClass,
                maxHP,currentHP,
                time,attackPoints,
                defPoints, level,
                magicDamage,maxMana, currentMana);
            csv_file.close();
            return newPlayer;
        }

        else if(playerClass == "Fighter"){
            unsigned int crit;
            csv_file>>crit;
            std::unique_ptr<Player> newPlayer;
            newPlayer = std::make_unique<Fighter>(
                name,playerClass,
                maxHP,currentHP,
                time,attackPoints,
                defPoints, level,
                crit);  
            csv_file.close();
            return newPlayer;
        }

        std::unique_ptr<Player> newPlayer;
        newPlayer = std::make_unique<Player>(name,playerClass,maxHP,currentHP,time,attackPoints,defPoints, level);

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

void saveFileNames(std::string newFilename, std::string filename){
    std::vector<std::string> files = loadFileNames();
    files.push_back(newFilename);
    std::ofstream csv_file(filename);
    if(csv_file.is_open()){
        for (auto name : files){
            csv_file<< name <<"\n";
        }
        csv_file.close();
        std::cout<<"Game got saved"<<std::endl; 
    }
    else{
        std::cout << "couldnt open file"<<std::endl;
    }
}
std::vector<std::string>loadFileNames(std::string filename){
    std::ifstream csv_file(filename);
    std::vector <std::string> files;
    if(csv_file.is_open()){
        std::vector <std::string> files;
        std::string line;
        int count = 1;
        while(getline(csv_file, line)){
            files.push_back(line);
            std::cout << count << ". : " << line << std::endl;
            count++;
        }
        if (files.size() == 0){
            std::cout << "no saved files aviable" << std::endl;
        }
        csv_file.close();
        return files;
    }
    else{
        std::cout << "couldn't open file" << std::endl;
        return files;
    }
}
void saveIntoFile(std::string filename, std::unique_ptr<Player> &player){
    filename = "../saves/saved_stats/" + filename;
    if (player->getPlayerClass() == "Mage"){
        // option 1 with temp variables
        std::vector<unsigned int> stats = player->getSpecificStats();
        saveStatsMage(player, stats[0], stats[1], stats[2], filename);
    }
    else if (player->getPlayerClass()=="Fighter"){
        std::vector<unsigned int> stats = player->getSpecificStats();
        saveStatsFighter(player, stats[0],filename);
    }
    else{
        saveStats(player,filename);
    } 
}


void saveStats(std::unique_ptr<Player> &player, std::string filename){
    std::ofstream csv_file(filename);
    if(csv_file.is_open()){

        csv_file << player->getName() << "\n";
        csv_file << player->getPlayerClass() << "\n";
        csv_file << player->getMaxHP()<< "\n";
        csv_file << player->getCurrentHP()<< "\n";
        csv_file << player->getTime()<< "\n";
        csv_file << player->getAttPoints() << "\n";
        csv_file << player->getDefPoints()<< "\n";
        csv_file << player->getLevel()<<"\n";
        csv_file.close();
        std::cout<<"Game got saved"<<std::endl; 
    }
    else{
        std::cout << "couldn't save stats trainee" << std::endl;
    }
}
void saveStatsMage(std::unique_ptr<Player> &player,unsigned int currMana, unsigned int maxMana, unsigned int magicDamage,std::string filename)
 {
 std::ofstream csv_file(filename);
    if(csv_file.is_open()){

        csv_file << player->getName() << "\n";
        csv_file << player->getPlayerClass() << "\n";
        csv_file << player->getMaxHP()<< "\n";
        csv_file << player->getCurrentHP()<< "\n";
        csv_file << player->getTime()<< "\n";
        csv_file << player->getAttPoints() << "\n";
        csv_file << player->getDefPoints()<< "\n";
        csv_file << player->getLevel()<< "\n";
        csv_file << currMana << "\n";
        csv_file << maxMana<< "\n";
        csv_file << magicDamage; 
        csv_file.close();
        std::cout<<"Game got saved"<<std::endl; 
    }
    else{
        std::cout << "couldn't save stats mage" << std::endl;
    }
}
void saveStatsFighter(std::unique_ptr<Player> &player, unsigned int critChance, std::string filename){
        std::ofstream csv_file(filename);
    if(csv_file.is_open()){

        csv_file << player->getName() << "\n";
        csv_file << player->getPlayerClass() << "\n";
        csv_file << player->getMaxHP()<< "\n";
        csv_file << player->getCurrentHP()<< "\n";
        csv_file << player->getTime()<< "\n";
        csv_file << player->getAttPoints() << "\n";
        csv_file << player->getDefPoints()<< "\n";
        csv_file << player->getLevel()<<"\n";
        csv_file << critChance;
 

        csv_file.close();
        std::cout<<"Game got saved"<<std::endl; 
    }
    else{
        std::cout << "couldn't save stats fighter" << std::endl;
    }
}
