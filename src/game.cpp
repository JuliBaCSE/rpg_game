#include <iostream>

#include "load_save.h"
#include "Player.h"
#include "Enemy.h"

// allgemeine Klasse und Player eins drueber


char mainMenu(){
    std::cout << "welcome to the game!" << std::endl;
    std::cout << "Enter one of the following option: " << std::endl;
    std::cout << "  - start a new Game press 'n'" << std::endl;
    std::cout << "  - load a past Game press 'l'" << std::endl;
    std::cout << "  - to exit press 'e'" << std::endl;
    char input;
    std::cin >> input;

    while(input != 'n' && input != 'l' && input != 'e'){
        std::cout<< "unknown input, try again"<< std::endl;
        std::cout << "Enter one of the following option: " << std::endl;
        std::cout << "  - start a new Game press 'n'" << std::endl;
        std::cout << "  - load a past Game press 'l'" << std::endl;
        std::cout << "  - to exit press 'e'" << std::endl;
        std::cin >> input;
    }
    return input;  
}
// std::unique_ptr<Player> loadSavedStats(std::string filename = "./saves/saved_stats.csv")
// {
//     std::ifstream csv_file(filename);
//     if(csv_file.is_open()){
//         std::string name;
//         int HP;
//         unsigned int time;
// // load time 
//         csv_file>>name;
//         csv_file>>HP;
//         csv_file>>time;
//         std::unique_ptr<Player> newPlayer;
//         newPlayer = std::make_unique<Player>(name,HP,time);

//         csv_file.close();
//         return newPlayer;
//     }
//     else{
//         std::cout << "couldn't open the file" << std::endl;
//     }
//     std::unique_ptr<Player> newPlayer;
//     newPlayer = std::make_unique<Player>("Unknown");
//     return newPlayer;
// }

// void saveStats(std::unique_ptr<Player> &player, std::string filename = "./saves/saved_stats.csv"){
//     std::ofstream csv_file(filename);
//     if(csv_file.is_open()){
//         csv_file << player->getName() << "\n";
//         csv_file << player->getHP()<< "\n";
//         csv_file << player->getTime();
//         csv_file.close();
//     }
//     else{
//         std::cout << "couldn't save stats" << std::endl;
//     }
// }

std::unique_ptr<Player> startGame(char input){
    if(input == 'n'){
        std::cout << "Please enter a name for your character" << std::endl;
        std::string name;
        std::cin >> name;
        std::unique_ptr<Player> newPlayer;
        newPlayer = std::make_unique<Player>(name);
        return newPlayer;
    }

    return loadSavedStats();
}

void inGame(std::unique_ptr<Player> &player){
    std::cout << "welcome to the game Player " << player->getName() <<"!" << std::endl;
    char input = 'p';
    while(input != 'e'){
        // add rest 
        std::cout << "Enter one of the following options to continue: " << std::endl;
        std::cout << "  - start a fight 'f'" << std::endl;
        std::cout << "  - show stats press 'p'" << std::endl;
        std::cout << "  - to heal press h" << std::endl;
        std::cout << "  - to save current game 's'" << std::endl;
        std::cout << "  - to exit press 'e'" << std::endl;
        std::cin >> input;


        if(input == 'f'){
            //fight function -> point zum gegner als input
            
            std::cout<< "Fight!!!!"<<std::endl;

            std::unique_ptr<Enemy> enemy;
            enemy = std::make_unique<Enemy>(); 
            player->fight(enemy);
            if(player->getHP() <= 0){
                std::cout << "You died!!" <<std::endl;
                std::cout << "GAME OVER!" <<std::endl;
                input = 'e'; // exit game
            }
            else{
                std::cout << "You won the fight!" <<std::endl;
                std::cout << "You have "<< player->getHP() << " HP left" << std::endl;
            }
        }
        else if (input == 'h'){
            player->restoreHP();
        }
        else if (input == 'p'){
            // time, attack points, defense -> new function show stats
            player->showStats();
        }
        else if (input == 's'){
            saveStats(player);
            std::cout<<"Game got saved"<<std::endl;
        }

    }
}

int main(){
    // class enemy
    char const userInput=mainMenu();
    if(userInput != 'e'){
        //create player as a pointer
        std::unique_ptr<Player> player = startGame(userInput);
        //inGame(pointer)
        inGame(player);
    }

    return 0;
}
