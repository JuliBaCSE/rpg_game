#include <iostream>
#include <memory>
#include "load_save.h"
#include "Player.h"
#include "Enemy.h"
#include "Table.h"
#include "Mage.h"
#include "Fighter.h"
#include "Bot.h"


char mainMenu(){
    show1( "welcome to the game!" );
    show1( "Enter one of the following option: " );
    show2( "  - start a new Game press"," 'n'" );
    show2( "  - load a past Game press"," 'l'" );
    show2("  - bot mode", " 'b'");
    show2( "  - to exit press"," 'e'" );
    char input;
    std::cin >> input;

    while(input != 'n' && input != 'l' && input != 'e' && input != 'b'){
        show1("unknown input, try again");
        show1( "Enter one of the following option: " );
        show2( "  - start a new Game press"," 'n'" );
        show2( "  - load a past Game press"," 'l'" );
        show2("  - bot mode", " 'b'");
        show2( "  - to exit press"," 'e'" );
        std::cin >> input;
    }
    return input;  
}

std::unique_ptr<Player> startGame(char input){
    if(input == 'n'){
        std::cout << "Please enter a name for your character" << std::endl;
        std::string name;
        std::cin >> name;
        std::unique_ptr<Player> newPlayer;
        newPlayer = std::make_unique<Player>(name);
        return newPlayer;
    }
    else{
        std::cout << "which game do you want to load <-> input the number: " << std::endl;
        std::vector<std::string> files = loadFileNames();
        if (files.size()!= 0){
            int fileNumber = 0;
            std::cin>>fileNumber;
            while (fileNumber < 1 || fileNumber > files.size()){
                std::cout << "invalid input !! ------>try again" << std::endl;
                std::cin>>fileNumber;
            }
            return loadSavedStats(files[fileNumber-1]);
        }
        else{
            std::cout << "seems there are no files so lets start a new game" <<std::endl;
            std::cout << "Please enter a name for your character" << std::endl;
            std::string name;
            std::cin >> name;
            std::unique_ptr<Player> newPlayer;
            newPlayer = std::make_unique<Player>(name);
            return newPlayer;
        }
    }
}

void inGame(std::unique_ptr<Player> &player){
    std::cout << "welcome to the game Player " << player->getName() <<"!" << std::endl;
    char input = 'p';
    while(input != 'e'){
        // add rest 
        show1( "Enter one of the following options to continue: " );
        show2( "  - start a fight ","'f'" );
        show2( "  - show stats press ","'p'" );
        show2( "  - to restore press ","'h'" );
        show2( "  - to save current game " ,"'s'" );
        show2( "  - to exit press ","'e'" );        
        std::cin >> input;

        if(input == 'f'){
            //fight function -> point zum gegner als input            
            std::cout<< "Fight!!!!"<<std::endl;
            std::unique_ptr<Enemy> enemy;
            enemy = std::make_unique<Enemy>(player->getTime(),player->getLevel()); 
            player->fight(enemy);
            if(player->getCurrentHP() <= 0){
                std::cout << "You were killed by " << enemy->enemyName << "!"<<std::endl;
                std::cout << "GAME OVER!" <<std::endl;
                break; // exit game
            }
            else{
                std::cout << "You won the fight!" <<std::endl;
                std::cout << "You have "<< player->getCurrentHP() << " HP left" << std::endl;
                player->levelUp();
            }
            if(player->getLevel() == 5){ //Choose new class after level 5
                std::cout << std::endl;
                std::cout << "Congrats you reach Level 5!! That means you are allowed to chose a new Class" << std::endl;
                std::cout << "Therefore you have 2 options:" << std::endl<< std::endl;
                show2(" 1. Mage: ", "with this class you will be able to cast unbeleavable strong magic spells");
                std::cout<<" 2. Fighter: with this class you will turn into a bloody fighter that can do critical Strikes once he is in a bloooody mood"<<std::endl;
      
                char choice = 'd';
                while(choice != 'm' && choice != 'f'){
                    std::cout << "Now do a wise choice!!"<< std::endl<< std::endl;
                    show2(" - Transform into a Mage press", "m");
                    show2(" - Transform to be a bloody fighter press", "f");
    
                    std::cin>>choice;
                    if(choice == 'm'){
                        player = std::make_unique<Mage>(player);
                        std::cout<< "Good choice!! Maybe you will become the new Gandalf!"
                        << "\nKeep in mind to use your new Power wisely"<<"\n"<<std::endl;
                        player->showStats();
                    }
                    else if(choice == 'f'){
                        player = std::make_unique<Fighter>(player);
                        std::cout<< "Good choice!! Maybe you will become the new Gimli!"
                        << "\n Keep in mind to use your new Strength wisely"
                        <<"\n those are your new Stats: "<<std::endl;
                        player->showStats();
                    }
                    else{
                        std::cout << "Seems that you aren't sure try it again!" << std::endl;
                    }
                }
            }
        }
        else if (input == 'h'){
            player->restoreHP();
        }
        else if (input == 'p'){
            player->showStats();
        }
        else if (input == 's'){
            show2("If you want to save into a new file press","n");
            show2("If you want to save into a old file press", "o");
            char fileChar;
            std::cin>>fileChar;
            if(fileChar == 'n'){
                std::cout << "type in the filename to save the Filename to the current Status"<<std::endl;
                std::string filename;
                std::cin >> filename;
                filename = filename + ".csv";
                saveFileNames(filename);
                saveIntoFile(filename, player);
            }
            else{
                std::cout << "which file do you want to override type in the number: "<<std::endl;
                std::vector<std::string> files = loadFileNames();
                if (files.size() < 1){
                    std::cout << "seems there are no files" <<std::endl;
                    std::cout << "type in the filename to save the Filename to the current Status"<<std::endl;
                    std::string filename;
                    std::cin >> filename;
                    filename = filename + ".csv";
                    saveIntoFile(filename, player);
                    saveFileNames(filename);
                }
                else{
                    int fileNumber = 0;
                    std::cin>>fileNumber;
                    while (fileNumber < 1 || fileNumber > files.size()){
                        std::cout << "invalid input !! ------>try again" << std::endl;
                        std::cin>>fileNumber;
                    }
                    saveIntoFile(files[fileNumber-1], player);    
                }
            }            

        }
    }
}

int main(){
    char const userInput=mainMenu();
    if(userInput != 'e' && userInput != 'b'){
        //create player as a pointer
        std::unique_ptr<Player> player = startGame(userInput);
        //inGame(pointer)
        inGame(player);
    }

    if (userInput == 'b') {
        //Simulate the programm
        Bot time_analysis;
    }
    return 0;
}
