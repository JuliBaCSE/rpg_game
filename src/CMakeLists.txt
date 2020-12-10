cmake_minimum_required(VERSION 3.8)
project(VisApp VERSION 0.1.0 LANGUAGES CXX)
add_executable(game game.cpp load_save.cpp load_save.h Player.cpp Player.h Enemy.h Enemy.cpp)
target_compile_features(game PUBLIC cxx_std_17)
