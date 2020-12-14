#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "Player.h"
#include <fstream>
#include <sstream>

std::unique_ptr<Player> loadSavedStats(std::string filename = "../saves/saved_stats.csv");

void saveStats(std::unique_ptr<Player> &player, std::string filename = "../saves/saved_stats.csv");


#endif
