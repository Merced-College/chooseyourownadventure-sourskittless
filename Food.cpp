#include "Food.h"
#include <iostream>

Food::Food(std::string type, int healthValue) 
    : type(type), healthValue(healthValue) {}

void Food::consume() const {
    std::cout << "\n>>> You eat the " << type << ". (+" << healthValue << " HP)" << std::endl;
}