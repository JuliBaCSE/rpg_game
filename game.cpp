#include <iostream>
#include <fstream>

class Player{
private:
//2 new var attack points and defense points ingame time
    unsigned int HP = 100;
    std::string charName;

public:
// restore health function (max health upper bound)
    std::string getName(){return charName;}
    unsigned int getHP (){return HP;}
//show stats function
    void fight(unsigned int damage=10){
        this->HP -= damage;
        // damage = attack points - defense points
        // damage >=0
        //fight = for loop till one die
        //increment ingame time
    }

    Player(std::string name): charName(name){};
    Player(std::string name, unsigned int HP): charName(name), HP(HP){};
};

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

Player loadSavedStats(std::string filename = "./saves/saved_stats.csv"){
    std::ifstream csv_file(filename);
    if(csv_file.is_open()){
        std::string name;
        unsigned int HP;

        csv_file>>name;
        csv_file>>HP;

        Player newPlayer(name,HP);

        csv_file.close();
        return newPlayer;
    }
    else{
        std::cout << "couldn't open the file" << std::endl;
    }
    Player dummyPlayer("Unknown");
    return dummyPlayer;
}

void saveStats(Player& player, std::string filename = "./saves/saved_stats.csv"){
    std::ofstream csv_file(filename);
    if(csv_file.is_open()){
        csv_file << player.getName() << "\n";
        csv_file <<player.getHP();
        csv_file.close();
    }
    else{
        std::cout << "couldn't save stats" << std::endl;
    }
}

Player startGame(char input){
    if(input == 'n'){
        std::cout << "Please enter a name for your character" << std::endl;
        std::string name;
        std::cin >> name;
        Player newPlayer(name);
        return newPlayer;
    }

    return loadSavedStats();
}

void inGame(Player player){
    std::cout << "welcome to the game Player " << player.getName() <<"!" << std::endl;
    char input = 'p';
    while(input != 'e'){

        std::cout << "Enter one of the following options to continue: " << std::endl;
        std::cout << "  - start a fight 'f'" << std::endl;
        std::cout << "  - show stats press 'p'" << std::endl;
        std::cout << "  - to save current game 's'" << std::endl;
        std::cout << "  - to exit press 'e'" << std::endl;
        std::cin >> input;


        if(input == 'f'){
            //fight function -> point zum gegner als input
            player.fight();

            std::cout<< "Fight!!!!"<<std::endl;
            std::cout << "you lost 10 hp!" << std::endl;
            if(player.getHP() <= 0){
                std::cout << "You died!!" <<std::endl;
                std::cout << "GAME OVER!" <<std::endl;
                input = 'e'; // exit game
            }
        }
        else if (input == 'p'){
            // time, attack points, defense -> new function show stats
            std::cout << player.getName() << " your current HP is " << player.getHP()<<std::endl;
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
        Player player = startGame(userInput);
        //inGame(pointer)
        inGame(player);
    }

    return 0;
}