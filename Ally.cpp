#include "Ally.h"
#include <iostream>

Ally::Ally(std::string name, std::string status, int boost) 
    : name(name), status(status), boost(boost) {}

void Ally::greet() const {
    std::cout << "\n[" << name << "]: " << status << std::endl;
    std::cout << ">>> They give you a +" << boost << " morale boost!" << std::endl;
}