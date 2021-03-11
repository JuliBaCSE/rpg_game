#include "Table.h"

//Single output
void show1(std::string a) {
    std::cout << std::setw(0) << std::setfill('.') << a;
    std::cout << std::endl;
    std::cout << std::endl;
}
//Doueble Output (unsigned int)
void showi(std::string a, unsigned int b) {
    std::cout << std::setw(0) << std::setfill('.') << a;
    std::cout << std::setw(40-a.size()) << std::setfill('.') << b;
    std::cout << std::endl;
    std::cout << std::endl;
}
//Double output
void show2(std::string a, std::string b) {
    std::cout << std::setw(0) << std::setfill('.') << a;
    std::cout << std::setw(50-a.size()) << std::setfill('.') << b;
    std::cout << std::endl;
    std::cout << std::endl;
}
