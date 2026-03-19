#include "Food.h"
#include <iostream>

Food::Food(std::string name, int benefit) 
    : name(name), benefit(benefit) {}

void Food::eat() const {
    std::cout << "\n>>> You eat the " << name << "." << std::endl;
    std::cout << ">>> You feel better! (+" << benefit << " benefit)" << std::endl;
}