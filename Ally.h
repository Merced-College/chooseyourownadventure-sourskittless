#ifndef ALLY_H
#define ALLY_H

#include <string>

class Ally {
private:
    std::string name;
    std::string status;
    int boost;

public:
    Ally(std::string name, std::string status, int boost);
    void greet() const; 
};

#endif