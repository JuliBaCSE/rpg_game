#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "Player.h"
#include "Mage.h"
#include "Fighter.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <filesystem>
// path to the file that holds all saved status names
static const std::string savedFiles = "../saves/saved_files.csv";


std::unique_ptr<Player> loadSavedStats(std::string filename);
//saves different file names for differen gamestatus
void saveFileNames(std::string newFilename, std::string filename = savedFiles);
//load a specific gamestatus
std::vector<std::string> loadFileNames(std::string filename = savedFiles);

//save call in main that calls dependent on player class different save function
void saveIntoFile(std::string filename,std::unique_ptr<Player> &player);

//saves a normal class
void saveStats(std::unique_ptr<Player> &player, std::string filename);
//saves a mage class
void saveStatsMage(std::unique_ptr<Player> &player,unsigned int currMana, unsigned int maxMana, unsigned int magicDamage, std::string filename);
//saves a fighter class
void saveStatsFighter(std::unique_ptr<Player> &player, unsigned int critChance, std::string filename);
#endif
