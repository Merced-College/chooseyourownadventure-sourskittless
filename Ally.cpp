#include "Ally.h"
#include <iostream>

Ally::Ally(std::string name, std::string dialogue) 
    : name(name), dialogue(dialogue) {}

void Ally::interact() const {
    std::cout << "\n>>> [" << name << "]: " << dialogue << std::endl;
}