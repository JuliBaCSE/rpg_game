#ifndef GAME_H
#define GAME_H




class Game{
private:
    std::unique_ptr<Player> player;

    //defines if new game or loaded Game
    //char userInput;

public:
    void inGame(std::unique_ptr<Player> &player);
    
    Game(std::unique_ptr<Player> player); 


    //Constructor der einen neuen Spieler erstellt
    //Constructor der einen Spieler laedt


};


#endif